#include "channel.h"


channel::channel(int waveform, int buffersize,  int samplerate)
{
    init(waveform,buffersize,samplerate);
}

void channel::init(int waveform, int buffersize, int samplerate)
{
    this->waveform=waveform;
    this->bufferSize=buffersize;
    this->samplerate=samplerate;
    buffer=new short[bufferSize];
    time =.0f;
    step=1.0f/samplerate;
}

channel::~channel()
{
    // if(buffer!=nullptr)
    // {
    //     delete [] buffer;
    // }
    // buffer=nullptr;
}

bool channel::setWaveform(int waveform)
{
    if(waveform >= 0 && waveform <4)
    {
        this->waveform=waveform;
        return true;
    }
    else
    {
        return false;
    }
}

int channel::getWaveform()
{
    return waveform;
}

void channel::run()
{
    double phase;
    double hertz=440;
    for(int i=0;i<bufferSize;i++)
    {
        phase=sin(hertz*M_PI*2*time);
        buffer[i]=short(phase*volume);
        time+=step;
    }    
}

short *channel::getBufferPtr()
{
    return buffer;
}