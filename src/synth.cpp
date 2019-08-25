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

    env=new envelope{VOICES};
    for(int i=0;i<VOICES;i++)
    {
        channelFloatBuffers[i]=new float[bufferSize];
    }

}

synth::~synth()
{
    delete [] buffer;
    delete [] floatBuffer;
    delete env;
    for(int i=0;i<VOICES;i++)
    {
        delete[] channelFloatBuffers[i];
    }
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
        floatBuffer[i]=0;
        for(int j=0;j<VOICES;j++)
        {
            if(decoder.isStriked(j))
            {
                env->trigger(j,time);
            }
            double freq=decoder.getFreq(j,time);
            double subFreq=decoder.getFreq(j,time,true);
            if(decoder.isfreqModulated(j))
            {
                freq*=env->getVolume(j,time)*env->getVolume(j,time);
                subFreq*=env->getVolume(j,time)*env->getVolume(j,time);
            }
                

            double wave=chan.get(env->getCurrentTime(j,time),decoder.getWaveform(j),freq)*decoder.getVolume(j);
            wave+=chan.get(env->getCurrentTime(j,time),decoder.getSubWaveform(j),subFreq)*decoder.getSubVolume(j);
            wave*=env->getVolume(j,time);

            channelFloatBuffers[j][i]=wave*.75;
            floatBuffer[i]+=wave*.1;
            buffer[i]+=wave*4096;
        }
        buffer[i]*=volume;
        time+=1.0/samplerate;
    }
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

float *synth::getFloatBufferPtr()
{
    return floatBuffer;
}

float *synth::getChannelFloatBuffer(int channel)
{
    if(channel<VOICES)
    {
        return(channelFloatBuffers[channel]);
    }
    else
    {
        return nullptr;
    }
}

float synth::getVolume()
{
    return this->volume;
}
