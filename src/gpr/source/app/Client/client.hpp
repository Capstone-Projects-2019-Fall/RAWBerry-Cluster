#pragma once


//Used for debugging sections
//comment out to remove debug messages
//#define DEBUG_MAIN 1
//#define DEBUG_SEND 1
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

using namespace std;
typedef int SOCKET;

//make a string of the server's url
string build_url();

//used to send command to rstp server (PLAY, OPTIONS, etc), then gets reply from server
static bool send_cmd(SOCKET rtsp_socket,
	string request, string &reply);


/*
	Warning: The send functions are not compatable with other rtsp servers.
	I was lazy and ignored standards since our server doesn't care
*/

//not actually used by our server
bool send_options(SOCKET rtsp_socket, int &request_count);
//used to descibe content wanted by the client, not too useful client side but the server expects the command
bool send_describe(SOCKET rtsp_socket, int &request_count);
//the setup command is actually useful, it's where our server sends the port used for recieving data
bool send_setup(SOCKET rtsp_socket, int &request_count, string &session_id);
//Tells the server to start sending frames
bool send_play(SOCKET rtsp_socket, int &request_count, string &session_id);

//starts up the rtsp session
bool session_handler(SOCKET rtsp_socket, int &request_count, string &session_id);



//sends frame to decoder
void frame_to_decoder(string frame);
//merge the packets into a single payload
string merge_packets(unsigned char **&frame_buffer, int packet_count);
//Get the packet's sequence number
uint32_t get_packet_sequence(unsigned char *packet);
//check if packet is the last one in sequence
bool is_last_packet(unsigned char p_byte);

//handles rpt packets
void handle_packet(unsigned char *&packet, unsigned char **&frame_buffer, int &packet_count);
//recieves rtp packets sent by the server
void receive_packets();

