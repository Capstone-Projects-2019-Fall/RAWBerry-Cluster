#include "./src/client.cpp"

/*
 / Used for debugging msgs in client.cpp
 / Comment out to remove debug messages
 / Moved here to avoid conflict with test.cpp
*/ 

//local def & instantiation to default locals - globaly defined as externs in header
string rtsp_a = RSTP_ADDRESS;
int rtsp_p = RTSP_PORT;
string rtsp_pth = RTSP_PATH;


int configure_URL(int argc, char **argv) {

	if (argc != 4) {//if not 3 necessary parameters, use defualt locals
		cout << "Using Default URL Parameters: "
			<< RSTP_ADDRESS << ", "
			<< RTSP_PORT << ", "
			<< RTSP_PATH;

		//leave globals unchanged from default instantiation
	}
	else { //otherwise, attempt to create socket using parameters - socket() handles error
		
		rtsp_a = argv[1];
		rtsp_p = atoi(argv[2]);	//cast string to int var
		rtsp_pth = argv[3];
		
		cout << "URL Parameters: "
			<< rtsp_a << ", "
			<< rtsp_p << ", "
			<< rtsp_pth;
	}
}

int main(int argc, char **argv){

	//for rtsp socket
	SOCKET rtsp_sock;
	sockaddr_in rtsp_addr;
	//for server controls
	int request_count = 1;
	string session_id;
	string server_url;



	//create socket for RTSP Connection
	rtsp_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (rtsp_sock < 0) { 
        printf("socket creation failed\n"); 
        exit(0); 
    } 

	configure_URL(argc, argv);//will use parameters, or set to default local values

	rtsp_addr.sin_family      = AF_INET; //IPv4 is fine
    rtsp_addr.sin_addr.s_addr = inet_addr(rtsp_a.c_str()); //IP address from argv[1] OR default locals
    rtsp_addr.sin_port        = htons(rtsp_p); //Port# from argv[2] OR default locals

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
			cout << "" << "rtsp_sock connected!" << "\n";
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