
//testing lib 
//#include "../test/catch.hpp"
//header
#include "./client.hpp"


#include "gpr.h"
#include "gpr_allocator.h"
#include "gpr_buffer.h"
#include "vc5_decoder.h"
#include "timer.h"
#include "config.h"
#include "gpr_parse_utils.h"

//#include <opencv2/legacy/constants_c.h>
//#include <opencv2/imgcodecs/imgcodecs_c.h>
//#include <opencv2/highgui/highgui_c.h>

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
		cout << "request: " << request <<"\n";
	#endif

	//get server url
	string url = build_url();

	#ifdef DEBUG_SEND
		cout << "server url = " << url << "\n";
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
			cout << "\n" << "send_options failed"	<< "\n";
		#endif

		return false;
	}
	
	if (!send_describe(rtsp_socket, request_count)){
				
		#ifdef DEBUG_SEND
			cout << "\n" << "send_describe failed"	<< "\n";
		#endif

		return false;
	}

	if (!send_setup(rtsp_socket, request_count, session_id)){

		#ifdef DEBUG_SEND
			cout << "\n" << "send_setup failed"	<< "\n";
		#endif

		 return false;
	}

	if (!send_play(rtsp_socket, request_count, session_id)){
		
		#ifdef DEBUG_SEND
			cout << "\n" << "send_play failed"	<< "\n";
		#endif

		return false;
	}

	//session setup success
	return true;	
}



//sends frame to decoder
void frame_to_decoder(string frame){
	
	//CvMat * image;
	printf("Writing %d Bytes to File",frame.length());
	FILE *file = fopen("/tmp/test", "w+");
	std::fwrite(frame.c_str(), frame.length(), 1, file);
	
	/* gpr_allocator allocator;
    allocator.Alloc = malloc;
    allocator.Free = free;
    
    gpr_parameters params;
    gpr_parameters_set_defaults(&params);
    
    gpr_buffer input_buffer  = { (void *)frame.c_str(), frame.length() };
    gpr_buffer output_buffer = { NULL, 0 };
    
    
    printf("Read:%d Bytes\n", input_buffer.size);
	
    gpr_parse_metadata( &allocator, &input_buffer, &params );

    gpr_rgb_buffer rgb_buffer = { NULL, 0, 0, 0 };
    GPR_RGB_RESOLUTION rgb_resolution = GPR_RGB_RESOLUTION_HALF;
    
    int rgb_file_bits = 16;
    
    int success = gpr_convert_gpr_to_rgb( &allocator, rgb_resolution, rgb_file_bits,  &input_buffer, &rgb_buffer );
    
    

    char header_text[100];

    sprintf( header_text, "P6\n%ld %ld\n65535\n", rgb_buffer.width, rgb_buffer.height );

            
    output_buffer.size   = rgb_buffer.size + strlen( header_text );
    output_buffer.buffer = allocator.Alloc( output_buffer.size );
    char* buffer_c = (char*)output_buffer.buffer;
            
    memcpy( buffer_c, header_text, strlen( header_text ) );
    memcpy( buffer_c + strlen( header_text ), rgb_buffer.buffer, rgb_buffer.size );

        
        
    printf("Decompressed Size\n", rgb_buffer.size);
    image = cvDecodeImageM((CvMat *)&output_buffer, CV_LOAD_IMAGE_COLOR);
	
	cvShowImage( "Display window", image );                // Show our image inside it.
    cvWaitKey(42); // Wait for a keystroke in the window*/
	return;
}

//combine all the payloads together into one giant payload
unsigned char* merge_frame(unsigned char **&frame_buffer, int packet_count){
	size_t size = 0;
	std::ostringstream frame;
	//check if all packets are assembled
	for (size_t i = 0; i < packet_count; i++){
		
		if (frame_buffer[i] != NULL){
			frame << frame_buffer[i];
		}

}
	printf("Frame Size is: %d", frame.str().length());
	frame_to_decoder(frame.str());
}

/*
Byte:     |      0        |      1        |      2 to 5   |      6 to 9       |      10 to 13     |       14+           |
    Bits: |0|1|2|3|4|5|6|7|0|1|2|3|4|5|6|7|   |   |   |   |    |    |    |    |    |    |    |    | | | | | | | | | | | |
          | V |P|X|   CC  |M|    PT       |Sequence Number|      TimeStamp    |      SSRC         |      *PAYLOAD*      |

*/

//Get the packet's sequence number
//broken up over 4 bytes, use binary operators to combine them,
uint32_t get_packet_sequence(unsigned char *packet){
	
	#ifdef DEBUG_PACKET
		cout << "get_packet_sequence()\n" 
		<< "packet[5] = " << (uint)packet[5] << "\n"
		<< "packet[4] = " << (uint)packet[4] << "\n"
		<< "packet[3] = " << (uint)packet[3] << "\n"
		<< "packet[2] = " << (uint)packet[2] << "\n";
	#endif

	// 0, 0, 0, p[5]
	uint seq = (uint8_t)packet[5];
	seq = seq << 8;
	// 0, 0, p[5], p[4]
	seq = seq | (uint8_t)packet[4];
	seq = seq << 8;
	//0, p[5], [p4], p[3]
	seq = seq | (uint8_t)packet[3];
	seq = seq << 8;
	//fully assembled
	seq = seq | (uint8_t)packet[2];

	#ifdef DEBUG_PACKET
		cout << "seq = " << seq << "\n";
	#endif
	
	return seq;
}

//check if packet is the last one in sequence
bool is_last_packet(unsigned char packet){
	//looking at the first bit in byte one.
	//M on the packet diagram
	if (packet >> 7 == 1){
		
		#ifdef DEBUG_PACKET
			cout << "LAST PACKET\n";
		#endif

		return true;
	}
	return false;
}


void handle_packet(unsigned char *&packet, unsigned char **&frame_buffer, int &packet_count){
	
	//get the sequence number of the packet
	uint sequence_num = get_packet_sequence(packet);

	//check if it's the last packet in the sequence
	bool last_packet = is_last_packet(packet[1]);

	//get_timestamp()

	//remove the 16 byte header, it's garbage now
	packet += RTP_HEADER_SIZE;

	//add packet to frame buffer
	frame_buffer[sequence_num] = packet;
	packet_count ++;
	printf("Packet Count: %d",packet_count);
	
	//if last packet in sequence
	if (last_packet){
		//merge packets together and send it to decoder
		printf("Packet Count Merged: %d",packet_count);
		merge_frame(frame_buffer, packet_count);
		packet_count = 0;
	}
}

void receive_packets(){

	//for tracking packets
	unsigned char **frame_buffer = (unsigned char **)malloc(sizeof(char) * BUFF_SIZE);
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
			cout << "<udp_sock bound to port "<< LOCAL_PORT << "\n";
		#endif
		
	}

	//collect packets forever
	//will add better conditions later
	while (true){
		unsigned char *packet = (unsigned char *)malloc(sizeof(char)*BUFF_SIZE);
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
			handle_packet(packet, frame_buffer, packet_count);
		} 
	}
}
    
