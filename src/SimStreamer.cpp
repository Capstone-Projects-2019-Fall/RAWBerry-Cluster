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
        }
        //stream frame
        streamFrame(bytes, len, curMsec);
        //free the buffer
    }
    free(buffer);

}

unsigned char * SimStreamer::readBuffer(){
    // open pipe
    FILE *pipe = fopen(INPUT_PIPE, "r");
    //if sucessful 
    if (pipe){
        //get size of file
        fseek(pipe, 0L, SEEK_END);
        size_t size = ftell(pipe);
        rewind(pipe);

        //if nothing in pipe
        if (size < 1){
            return NULL;
        }        
        //read input from the pipe
        unsigned char *buffer = (unsigned char *) malloc(sizeof(char) * size);

        fread(buffer, size, 1, pipe);

        printf(" 1 %s\n", buffer);

        //close the pipe 
        fclose(pipe);

        //return the buffer
        return buffer;
    }
    //open failed, panic
    else {

    }
}