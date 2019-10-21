#pragma once
#include "CStreamer.h"

#define INPUT_PIPE "/tmp/pipe"

class SimStreamer : public CStreamer
{
    bool m_showBig;
public:
    SimStreamer(SOCKET aClient, bool showBig);

    virtual void    streamImage(uint32_t curMsec);
private:
    unsigned char * readBuffer();
};