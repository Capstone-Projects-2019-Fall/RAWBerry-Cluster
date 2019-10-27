#include "SimStreamer.h"
#include <stdio.h>  
#include <fcntl.h> 
#include <sys/stat.h>
#include <string.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
SimStreamer::SimStreamer(SOCKET aClient, bool showBig) : CStreamer(aClient, showBig ? 800 : 640, showBig ? 600 : 480)
{
    m_showBig = showBig;
}

//Gets an imaage/fram from the named input pipe and then sends it to be streamed
void SimStreamer::streamImage(uint32_t curMsec)
{
    //get buffer
    unsigned char *buffer = readPipe();
    
    //if buffer not NULL
    if (buffer != NULL){
        BufPtr bytes = buffer;
        //get length
        uint32_t len = 0;
        for(size_t length = 0; buffer[length] != '\0'; length++){
            len = length;
            printf("len: %lu\n", length);
        }
        //stream frame
        puts("streamFrame 0");
        streamFrame(bytes, len, curMsec);
        puts("streamFrame 1");
        //free the buffer
    }
    free(buffer);

}

//
unsigned char * SimStreamer::readPipe(){
    
    int pipe_fd;


    pipe_fd = open(INPUT_PIPE, O_RDONLY);
    if (pipe){
        read(pipe_fd, frame_size, )
        
    }
    unsigned char *buffer = (unsigned char *) malloc(sizeof(char) * BUFF_SIZE);
    read(pipe_fd, buffer, BUFF_SIZE);
    return buffer;
    
    #ifdef N
    // open named pip
    FILE *pipe = fopen(INPUT_PIPE, "r");
    //if sucessful 
    if (pipe){
        puts("Pipe Open");
        //read input from the pipe
        unsigned char *buffer = (unsigned char *) malloc(sizeof(char) * BUFF_SIZE);
        fread(buffer, BUFF_SIZE, 1, pipe);
        //close the pipe 
        fclose(pipe);

        //return the buffer
        return buffer;
    }
    //open failed, panic
    else {
        puts("PIPE Failed :(");
        return NULL;
    }
    #endif
}