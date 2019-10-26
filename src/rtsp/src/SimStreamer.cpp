#include "SimStreamer.h"
#include <stdio.h>  
#include <fcntl.h> 
#include <sys/stat.h>
SimStreamer::SimStreamer(SOCKET aClient, bool showBig) : CStreamer(aClient, showBig ? 800 : 640, showBig ? 600 : 480)
{
    m_showBig = showBig;
}


void SimStreamer::streamImage(uint32_t curMsec)
{
    //get buffer
    unsigned char *buffer = readBuffer();
    
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
        streamFrame(bytes, len, curMsec);
        //free the buffer
    }
    free(buffer);

}

unsigned char * SimStreamer::readBuffer(){
    // open named pipe
    FILE *pipe = fopen(INPUT_PIPE, "r");
    //if sucessful 
    if (pipe){
           
        //read input from the pipe
        unsigned char *buffer = (unsigned char *) malloc(sizeof(char) * BUFF_SIZE);
        fread(buffer, BUFF_SIZE, 1, pipe);
        
        printf("%s", buffer);
        //close the pipe 
        fclose(pipe);

        //return the buffer
        return buffer;
    }
    //open failed, panic
    else {
        return NULL;
    }
}