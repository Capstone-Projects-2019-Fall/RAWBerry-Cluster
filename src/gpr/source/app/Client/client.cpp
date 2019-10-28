//Used for debugging sections
//comment out to remove debug messages
#define DEBUG_MAIN 1
#define DEBUG_SEND 1
#define DEBUG_PACKET 1

//for socket connections
#define RSTP_ADDRESS "127.0.1.1"
#define RTSP_PORT 8554
#define RTSP_PATH "/mjpeg/1"
#define BUFF_SIZE 4096

//max time to wait for a packet
#define MAX_WAIT 1
//local port for UDP stream
#define LOCAL_PORT 8888
//our *MODIFIED* RTP header size
#define RTP_HEADER_SIZE 14


#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <netdb.h> 

#include "gpr.h"
#include "gpr_allocator.h"
#include "gpr_buffer.h"
#include "vc5_decoder.h"
#include "timer.h"
#include "config.h"

using namespace std;
typedef int SOCKET;

//make a string of the server's url
string build_url(){

	ostringstream url;

	url << "rstp://" << RSTP_ADDRESS << ":" << RTSP_PORT << RTSP_PATH;

	return url.str();

}

//used to send command to rstp server (PLAY, OPTIONS, etc), then gets reply from server
static bool send_cmd(SOCKET rtsp_socket,
	string request, string &reply){


	#ifdef DEBUG_SEND
		cout <<"\n---------------------------------\n" << "<request>\n" << request <<"\n---------------------------------\n\n";
	#endif

	//get server url
	string url = build_url();

	#ifdef DEBUG_SEND
		cout << "\n---------------------------------\n" << "<server url>\n" << url << "\n---------------------------------\n\n";
	#endif
	
	//send request to server
	if (send(rtsp_socket, request.c_str(),
		static_cast<int>(request.size()), 0) == request.size())
	{
		char buffer[BUFF_SIZE];
		int bytes = recv(rtsp_socket, buffer, BUFF_SIZE, 0);
		switch (bytes)
		{
		case -1: //Socket error
		case 0: // Socket was closed
			
			break;

		default:
			//get reply
			reply = string(buffer, bytes);
			
			#ifdef DEBUG_SEND
				cout << "\n---------------------------------\n" << "<reply>\n" << reply << "\n---------------------------------\n\n" ;
			#endif

			//msg sent and reply recieved successfully
			return true;
			break; 
		}
	}
	//no reply, something went wrong
	return false;
}


/*
	Warning: The send functions are not compatable with other rtsp servers.
	I was lazy and ignored standards since our server doesn't care
*/

bool send_options(SOCKET rtsp_socket, int &request_count){
	
	ostringstream request;
	request << "OPTIONS " << build_url() << " RTSP/1.0\r\n"
		<< "CSeq: " << request_count << "\r\n"
		<< "Password=passw0rd\r\n"  //<= not actually my password, I swear.
		<< "user=admin\r\n"
		<< "\r\n";
	string reply;
	return send_cmd(rtsp_socket, request.str(), reply);
}
bool send_describe(SOCKET rtsp_socket, int &request_count){
	//build the request
	ostringstream request;
	request << "DESCRIBE " << build_url() << " RTSP/1.0\r\n"
		<< "CSeq: " << request_count << "\r\n"
		<< "blah\r\n"
		<< "Blahhhh\r\n"
		<< "\r\n";

	request_count++;

	string reply;
	return send_cmd(rtsp_socket, request.str(), reply);
}

//ok, I actually followed the standards on this one.
bool send_setup(SOCKET rtsp_socket, int &request_count, string &session_id){
	
	ostringstream request;
	request << "SETUP " << build_url << " RTSP/1.0\r\n"
		<< "CSeq: " << request_count << "\r\n"
		<< "Transport: RTP/AVP;unicast;client_port=" << LOCAL_PORT << "-" << LOCAL_PORT + 1 << "\r\n" //sending local port to server
		<< "\r\n\r\n";
	
	request_count++;

	string reply;
	//send cmd to server
	if (!send_cmd(rtsp_socket, request.str(), reply))
		return false; // if send failed or no response

	//get session id from reply
	size_t a = reply.find("Session: ");
	size_t b = reply.find("\r", a);
	session_id = reply.substr(a, b-a);
	
	return true;

}

bool send_play(SOCKET rtsp_socket, int &request_count, string &session_id){
	ostringstream request;
	
	request << "PLAY " << build_url << " RTSP/1.0\r\n"
		<< "CSeq: " << request_count << "\r\n"
		<< "Session: " << session_id << "\r\n"
		<< "\r\n\r\n";
	
	request_count++;
	string reply;
	return send_cmd(rtsp_socket, request.str(), reply);
}

bool session_handler(SOCKET rtsp_socket, int &request_count, string &session_id){
	

	//clear the session id
	session_id = "";

	// Send OPTIONS, DESCRIBE, SETUP, and PLAY requests to set up RTSP
	if (!send_options(rtsp_socket, request_count)){
				
		#ifdef DEBUG_SEND
			cout << "!!!!!!!!!!!!!\n" << "send_options failed"	<< "\n!!!!!!!!!!!!!!!!!!\n";
		#endif

		return false;
	}

	if (!send_describe(rtsp_socket, request_count)){
				
		#ifdef DEBUG_SEND
			cout << "!!!!!!!!!!!!!\n" << "send_describe failed"	<< "\n!!!!!!!!!!!!!!!!!!\n";
		#endif

		return false;
	}

	if (!send_setup(rtsp_socket, request_count, session_id)){

		#ifdef DEBUG_SEND
			cout << "!!!!!!!!!!!!!\n" << "send_setup failed"	<< "\n!!!!!!!!!!!!!!!!!!\n";
		#endif

		 return false;
	}

	if (!send_play(rtsp_socket, request_count, session_id)){
		
		#ifdef DEBUG_SEND
			cout << "!!!!!!!!!!!!!\n" << "send_play failed"	<< "\n!!!!!!!!!!!!!!!!!!\n";
		#endif

		return false;
	}

	//session setup success
	return true;	
}

//sends frame to decoder
void frame_to_decoder(string frame){
	printf("Writing Frame\n");
	FILE *file = fopen("/tmp/test.mp4", "w+");
	printf("Frame Length: %d\n", frame.length());
	std::fwrite(frame.c_str(), frame.length(), 1, file);
	fclose(file);
	
	string s = frame.c_str();
	char *c = &s[0];
	
	gpr_buffer vc5_image = { c, frame.length() };
	if( write_to_file( &vc5_image, "/CDNG/TEST.VC5" ) )
        {
            puts("Something Very Bad Happened");
        }
	CODEC_ERROR error = CODEC_ERROR_OKAY;
    
        vc5_decoder_parameters vc5_decoder_params;
        vc5_decoder_parameters_set_default(&vc5_decoder_params);
        vc5_decoder_params.enabled_parts = VC5_ENABLED_PARTS;
        vc5_decoder_params.mem_alloc     = malloc;
        vc5_decoder_params.mem_free      = free;

        gpr_buffer raw_image = { NULL, 0  };
        gpr_rgb_buffer rgb_image = { NULL, 0, 0, 0  };
        
    
        TIMER timer; // Performance timer
        InitTimer(&timer);
    
        StartTimer(&timer);
        

        puts("Trying Decode");
        vc5_decoder_process( &vc5_decoder_params, &vc5_image, &raw_image, &rgb_image );
        
        StopTimer(&timer);
        
        printf("Decompressed Size", raw_image.size);
	return;
}

void merge_frame(char **&frame_buffer, int packet_count){
	size_t size = 0;
	std::ostringstream frame;
	//check if all packets are assembled
	printf("NUM PACKETS:%d\n",packet_count);
	for (size_t i = 0; i < packet_count; i++){
		
		if (frame_buffer[i] != NULL){
			frame << frame_buffer[i];
		}

		else {
			puts("Missed Packet");
			
			/* 
			missing a packet :(
			TODO: Find better way of handling this (Maybe spin off a thread that waits for the missing frame?)
			*/

			//for now, just give up and clear the memory
			for (size_t j = 0; j < (packet_count -1) ; j++){
				free(frame_buffer[j]);
			}
			free(frame_buffer);
			return;
		}

	}
	printf("Rec Frame Length: %d\n", frame.str().length());
	frame_to_decoder(frame.str());
}

// TODO: Break up into smaller functions
// process packets and adds them to a buffer.
void do_packet_stuff(char *&packet, char **&frame_buffer, int &packet_count){
	#ifdef DEBUG_PACKET
	cout << "\nPACKET[1] =" << (uint)packet[1] << "\n";
	#endif
	//check if it's the last packet in the sequence
	bool last_packet = false;
	//if first bit of p[1] == 1
	if ((packet[1] >> 7) == 1){
		last_packet = true;
		#ifdef DEBUG_PACKET
			puts("LAST PACKET");
			cout << packet[1] << "\n";
		#endif
	}


	//get the packet's sequence number
	//split between 4 bytes in the packet
	//Assumes client computer isn't a dinosaur and that an int is 4 bytes
	uint seq1 = packet[2];
	uint seq2 = packet[3];
	uint seq3 = packet[4];
	uint seq4 = packet[5];	
	//combine into one int
	uint seq	= seq1 | (seq2 << 8) | (seq3 << 16) | (seq4 << 24);
	


	#ifdef DEBUG_PACKET
		printf("Seq1: %u\nSeq2: %u\nSeq3: %u\nSeq4: %u\nSeq: %hu", seq1, seq2, seq3, seq4, seq);
	#endif

	//remove the 16 byte header, it's garbage now
	packet += RTP_HEADER_SIZE;

	
	//add packet to frame buffer
	frame_buffer[seq] = packet;
	packet_count ++;
	
	//if last packet in sequence
	if (last_packet){
		//merge packets together and send it to decoder
		merge_frame(frame_buffer, packet_count);
		packet_count = 0;
		return;
	}
}
//
void handle_udp_packets(){

	//for tracking packets
	char **frame_buffer = (char **)malloc(sizeof(char) * BUFF_SIZE);
	int packet_count = 0;

	//for udp stream
	SOCKET udp_sock;
	sockaddr_in udp_addr;

	//create socket for UDP connection
	udp_sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (udp_sock < 0){
		printf("udp_socket creation failed\n"); 
        exit(0);
	}

	udp_addr.sin_family = AF_INET;
	udp_addr.sin_addr.s_addr = INADDR_ANY;
	udp_addr.sin_port = htons(LOCAL_PORT);

	//bind socket to port
	if(bind(udp_sock, reinterpret_cast<sockaddr *>(&udp_addr), sizeof(udp_addr)) < 0){
		//if bind failed
		puts("udp_socket bind failed");
		exit(0);
	}
	else{

		#ifdef DEBUG_PACKET
			cout << "<<\n------------------------\n" << "udp_sock bound to port " << LOCAL_PORT << "\n------------------------\n";
		#endif
		
	}

	//collect packets forever
	//will add better conditions later
	while (true){
		char *packet = (char *)malloc(sizeof(char)*BUFF_SIZE);
		//get next packet
		int bytes = recv(udp_sock, packet, BUFF_SIZE, 0);
		
		//bad or no packet
		if (bytes < 1){
			#ifdef DEBUG_PACKET
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << "packet not read" << "\n!!!!!!!!!!!!!!!!!!!!!!\n";
			#endif
		}
		//good packet
		else{
			do_packet_stuff(packet, frame_buffer, packet_count);
			cout << "<Packet>\n" << bytes << "\n";
		} 
	}
	

	

	
}

int main(){

	//for rtsp socket
	SOCKET rtsp_sock;
	sockaddr_in rtsp_addr;
	//for server controls
	int request_count = 1;
	string session_id;
	string server_url;



	//create socket for RTSP Connection
	rtsp_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	//SET TO IPV6 SOON!
	if (rtsp_sock < 0) { 
        printf("socket creation failed\n"); 
        exit(0); 
    } 

	rtsp_addr.sin_family      = AF_INET;					//NEED TO SWITCH TO IPV6 BEFORE DEMO
    rtsp_addr.sin_addr.s_addr = INADDR_ANY;					//IP doesn't matter yet, testing locally. FIX BEFORE DEMO!
    rtsp_addr.sin_port        = htons(8554);                // listen on RTSP port 8554

	/*
	TODO: Loop forever without breaking 
	*/
	//while (true)
	//{
	
	//connect to socket
    if (connect(rtsp_sock, 
		reinterpret_cast<sockaddr *>(&rtsp_addr), sizeof(rtsp_addr)) < 0){
			//connect failed :(
			puts("Could not connect to server.");
		}
	
	//else socket success
	else {

		#ifdef DEBUG_MAIN
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << "rtsp_sock connected!" << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
		#endif
	
		//handle rtsp session
		if(session_handler(rtsp_sock, request_count, session_id) == false){
			//session handling failed :(
				//Blame the server
				cout << "Server Error\n";
			
				#ifdef DEBUG_MAIN
				cout << "Yep, couldn't be the client. I'm *PERFECT*\n";
				#endif

		}
		//else session looks good
		else{
			printf("handling Packets\n");
			handle_udp_packets();

		}


		close(rtsp_sock);
		}
	//}
}
    
