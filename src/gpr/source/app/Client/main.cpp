#include "client.hpp"

#include <opencv2/core/core_c.h>
#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <opencv2/highgui/highgui_c.h>
//Used for debugging msgs in client.pp
//comment out to remove debug messages
//#define DEBUG_MAIN 1
//#define DEBUG_SEND 1
#define DEBUG_PACKET 1

int main(){
	cvNamedWindow( "Display window", CV_WINDOW_AUTOSIZE ); // Create a window for display.
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
			receive_packets();

		}


		close(rtsp_sock);
		}
	//}
}
