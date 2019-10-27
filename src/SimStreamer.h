#pragma once
#include "CStreamer.h"

#define INPUT_PIPE "/tmp/pipe"
#define BUFF_SIZE 400000000

class SimStreamer : public CStreamer
{
    bool m_showBig;
public:
    SimStreamer(SOCKET aClient, bool showBig);

    virtual void    streamImage(uint32_t curMsec);
private:
    unsigned char * readPipe();
};