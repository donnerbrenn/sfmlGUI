#include "synth.h"

synth::synth(int channels,int bufferSize,int samplerate, double volume)
{
    this->channelCnt=channels;
    this->samplerate=samplerate;
    this->bufferSize=bufferSize;
    this->volume=volume;
    this->buffer=new short[bufferSize]{0};
    this->floatBuffer=new float[bufferSize]{0};
    channel newChan{samplerate,volume};
    chan=newChan;

    initialize(1,samplerate);
    
}

synth::~synth()
{
    delete [] buffer;
    delete [] floatBuffer;
}

short *synth::getBufferPtr()
{
    return buffer;
}

void synth::setVolume(double volume)
{
    this->volume=volume;        
}

bool synth::onGetData(Chunk& data)
{
    data.samples=buffer;
    data.sampleCount=bufferSize;
    clearBuffer();

    for(int i=0;i<bufferSize;i++)
    {
        for(int j=0;j<decoder.getChannelCnt();j++)
        {
            buffer[i]+=chan.get(time,decoder.getWaveform(j),decoder.getFreq(j,time));
        }
        buffer[i]*=volume;
        time+=1.0/samplerate;
    }

    convertShortToFloatBuffer();
    return true;
}

void synth::onSeek(sf::Time timeOffset)
{

}

void synth::clearBuffer()
{
    for(int i=0;i<bufferSize;i++)
    {
        buffer[i]=0;
    }
}

void synth::convertShortToFloatBuffer()
{
    for(int i=0;i<bufferSize;i++)
    {
        floatBuffer[i]=float(buffer[i]/32768.0);
    }
}

float *synth::getFloatBufferPtr()
{
    return floatBuffer;
}