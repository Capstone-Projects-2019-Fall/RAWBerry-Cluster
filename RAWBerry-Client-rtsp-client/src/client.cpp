
//#define DEBUG_MAIN 1
//#define DEBUG_SEND 1
//#define DEBUG_PACKET 1	
//#define DEBUG_WRITE 1
//#define DEBUG_MERGE 1

//testing lib 
#include "../test/catch.hpp"
//header
#include "./client.hpp"

using namespace std;
typedef int SOCKET;
//holds total expected size of the frame
uint64_t frame_size;


//make a string of the server's url
string build_url(){

	ostringstream url;

	url << "rstp://" << rtsp_a << ":" << rtsp_p << rtsp_pth;

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
void frame_to_decoder(unsigned char ** packet_buffer, int packet_count, uint sequence_num){
	#ifdef DEBUG_WRITE
		cout << "Writing frame to file\n";
	#endif
	string path = "/tmp/"+ std::to_string(sequence_num) +".GPR";
	FILE *file = fopen(path.c_str(), "w+");
	for (int i = 0; i < packet_count; i++){
		//if missing packet
		if (*packet_buffer == NULL){
			cout << "MISSING Packet No:" << i << "\n";
			exit(EXIT_FAILURE);
		}
		//if regular packet
		if (i < packet_count -1){
			printf("Packet No: %d\n", i);
			fwrite(*packet_buffer, MAX_PACKET_SIZE, 1, file);
			packet_buffer++;
		}
		//else last packet
		else {
			printf("Last Packet No: %d\nsize: ", i);
			printf("%" PRIu64 "\n", frame_size % MAX_PACKET_SIZE);

			//used calculated last packet size, since it can be between 1 and 1100
			fwrite(*packet_buffer, frame_size % MAX_PACKET_SIZE, 1, file);
			packet_buffer++;
			//for (i=0; i < 912; ++i)
    		//cout << *packet_buffer++ << "";
		}
	}
	fclose(file);
	//exit (EXIT_SUCCESS);
	return;
}

//currently not in use
#ifdef N
//combine all the payloads together into one giant payload
unsigned char * merge_frame(unsigned char *packet_buffer[], int packet_count){
	
	//used to write packet payloads into a single string of uchars
	unsigned char *frame = (unsigned char *)(malloc(sizeof(unsigned char) * frame_size));
	unsigned char *frame_ptr = frame;

	//used to read through the packet_buffer
	unsigned char **buf_ptr = packet_buffer;

	//track bytes writen to frame
	int bytes = 0;
	//loop through each packet
	for (int i = 0; i < packet_count; i++){
		//loop through each byte of packet, minus the header size
		#ifdef DEBUG_MERGE
			cout << "Merging packet " << i <<"\n";
		#endif

		for(int j = 0; j < MAX_PACKET_SIZE - RTP_HEADER_SIZE; j ++){
			//stop at end of last packet, which may be shorter than the MAX_PACKET_SIZE
			if (bytes >= frame_size){
				break;
			}
			bytes++; 

			#ifdef DEBUG_MERGE
				cout << "Wrote byte " << j <<" to frame\n";
			#endif
		}
		buf_ptr ++;
	}
	unsigned char **buf_ptr = packet_buffer;
	//string stream used to write input from each packet
	ostringstream frame;
	
	#ifdef DEBUG_MERGE
		cout << "merging packets\n";
	#endif

	//go through each packet
	for (size_t i = 0; i < packet_count; i++){
		if (*buf_ptr == NULL){
			//missing packet, handle this
			#ifdef DEBUG_MERGE
				cout << "NULL packet found in merge_frame()\n";
			#endif
			return NULL;
		}
		//else 
		else{
			frame << *buf_ptr;
			buf_ptr++;
			#ifdef DEBUG_MERGE
				cout << "merged packet " << i << "\n";
			#endif
		}
	}
	//return the frame as a pointer to an usigned char
	return (unsigned char *)frame.str().c_str();
	
	
}
#endif

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
		
		<< "packet[0] = " << (uint)packet[0] << "\n"
		<< "packet[1] = " << (uint)packet[1] << "\n" 
		<< "packet[2] = " << (uint)packet[2] << "\n"
		<< "packet[3] = " << (uint)packet[3] << "\n"
		<< "packet[4] = " << (uint)packet[4] << "\n"
		<< "packet[5] = " << (uint)packet[5] << "\n"
		<< "packet[6] = " << (uint)packet[6] << "\n"
		<< "packet[7] = " << (uint)packet[7] << "\n"
		<< "packet[8] = " << (uint)packet[8] << "\n"
		<< "packet[9] = " << (uint)packet[9] << "\n"
		<< "packet[10] = " << (uint)packet[10] << "\n"
		<< "packet[11] = " << (uint)packet[11] << "\n"
		<< "packet[12] = " << (uint)packet[12] << "\n"
		<< "packet[13] = " << (uint)packet[13] << "\n"
		//<< "packet[14] = " << (uint)packet[14] << "\n"
		//<< "packet[15] = " << (uint)packet[15] << "\n"
		//<< "packet[16] = " << (uint)packet[16] << "\n"
		//<< "packet[17] = " << (uint)packet[17] << "\n";
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


void handle_packet(unsigned char *packet, unsigned char *frame_buffer[], int &packet_count){
	
	//get the sequence number of the packet
	uint sequence_num = get_packet_sequence(packet);

	//check if it's the last packet in the sequence
	bool last_packet = is_last_packet(packet[1]);

	//get_timestamp()

	//remove the 14 byte header, it's garbage now
	packet += RTP_HEADER_SIZE;

	//add packet to frame buffer
	frame_buffer[sequence_num] = packet;
	packet_count ++;
	
	//if last packet in sequence
	if (last_packet){
		//send packets to decoder
		frame_to_decoder(frame_buffer, packet_count,sequence_num);
		packet_count = 0;
		//reset frame size
		frame_size = 0;
	}
}

void receive_packets(){

	//for tracking packets
	unsigned char *frame_buffer[MAX_PACKET_COUNT];
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

	frame_size = 0;
	//collect packets forever
	//will add better conditions later
	while (true){
		unsigned char *packet = (unsigned char *)malloc(sizeof(unsigned char *) * (MAX_PACKET_SIZE + RTP_HEADER_SIZE));
		
		//get next packet
		int bytes = recv(udp_sock, packet, MAX_PACKET_SIZE + RTP_HEADER_SIZE, 0);
		
		//bad or no packet
		if (bytes < 1){
			#ifdef DEBUG_PACKET
				cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << "packet not read" << "\n!!!!!!!!!!!!!!!!!!!!!!\n";
			#endif
		}
		//good packet
		else{
			frame_size += bytes - RTP_HEADER_SIZE;
			handle_packet(packet, frame_buffer, packet_count);
		} 
	}
}
    
