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
    size_t *frame_size = (size_t*)malloc(sizeof(size_t));
    size_t bytes_read = 0;
    int pipe_fd;


    pipe_fd = open(INPUT_PIPE, O_RDONLY);
    if (pipe){
        //get size of frame
        puts("Reading Pipe");
        read(pipe_fd, frame_size, sizeof(size_t));
        printf("Frame is %d Bytes\n", *frame_size);
        //read untill full frame is captured
        unsigned char *buffer = (unsigned char*)malloc(*frame_size + 1);
        while (bytes_read != *frame_size){
            bytes_read += read(pipe_fd, buffer, *frame_size - bytes_read);
            //printf("Read %d Bytes\n", bytes_read);
        }
        //return buffer
        return buffer;
        
    }
    else return NULL;
}
    
