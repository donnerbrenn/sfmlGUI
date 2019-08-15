#include "mixer.h"


mixer::mixer(int channelCnt, int buffersize, int samplerate)
{
    this->samplerate=samplerate;
    this->buffersize=buffersize;
    for(int i=0;i<channelCnt;i++)
    {
        channels.emplace_back(*new channel(sine,buffersize,samplerate));
    }
    buffer = new short[buffersize];
}

mixer::~mixer()
{

}

bool mixer::setWaveform(int channel, int waveform)
{
    if(channel >=0 && channel < channels.size())
    {
        return channels [channel].setWaveform(waveform);
    }
    else
    {
        return false;
    }
}

int mixer::getWaveform(int channel)
{
    if(channel >=0 && channel < channels.size())
    {
        return channels[channel].getWaveform();
    }
    else
    {
        return(-1);
    }
}

void mixer::run()
{
    clear();
    for(int i=0;i<channels.size();i++)
    {
        channels[i].run();
        mix(buffer,channels[i].getBufferPtr(),buffersize);
    }
}

void mixer::mix(short *a, short *b, int size)
{
    if (size>buffersize)
    {
        size=buffersize;
    }
    for(int i=0;i<size;i++)
    {
        a[i]+=b[i]*this->volume;
    }
    std::cout << volume << "\n";
}

void mixer::clear()
{
    for(int i=0;i<buffersize;i++)
    {
        buffer[i]=0;
    }
}

short *mixer::getBufferPtr()
{
    return buffer;
}

int mixer::getBufferSize()
{
    return buffersize;
}

void mixer::setVolume(double value)
{
    std::cout << volume << "\n";
}