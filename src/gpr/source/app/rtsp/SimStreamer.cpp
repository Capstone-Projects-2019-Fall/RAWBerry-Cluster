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
    int len = 0;
    //get buffer
    unsigned char *buffer = readPipe(len);
    
    //if buffer not NULL
    if (buffer != NULL){
        BufPtr bytes = buffer;
       for(size_t length = 0; buffer[length] != '\0'; length++){
            len = length;
           printf("len: %lu\n", length);
       }
        //stream frame
        puts("Begin Frame");
        streamFrame(bytes, (len -1), curMsec);
        puts("End Frame");
        //free the buffer
        free(buffer);
    }

}

//
unsigned char * SimStreamer::readPipe(int &len){
    unsigned char *buffer;
    unsigned char *buff_pointer = buffer; 
    
    int bytes_read = 0;
    
    int pipe_fd = open(INPUT_PIPE, O_RDONLY);
    if (pipe){
        //get size of frame
        read(pipe_fd, &len, sizeof(int));
        printf("Expected frame size: %d \n", len);
        //malloc mem for buffer
        buffer = (unsigned char *)malloc(len);

        while (bytes_read != len){
            bytes_read += read(pipe_fd, (buffer+bytes_read), (len - bytes_read));
            printf("Bytes Read: %d \nFrame Size: %d\n", bytes_read, len);
        }
        
        return buffer;
        //return NULL;
        
    }
    else return NULL;
}
    
