#include "synth.h"

synth::synth(int channels,int bufferSize,int samplerate, double volume)
{
    this->channelCnt=channels;
    this->samplerate=samplerate;
    this->bufferSize=bufferSize;
    this->volume=volume;
    this->buffer=new short[bufferSize];
    this->floatBuffer=new float[bufferSize];
    channel newChan{samplerate,volume};
    chan=newChan;
    initialize(1,samplerate);

    env=new envelope{VOICES};
    for(int i=0;i<VOICES;i++)
    {
        channelFloatBuffers[i]=new float[bufferSize];
        mode useFilter=descriptions[i].useFilter;
        double cutoff=descriptions[i].cutoff;
        double resonance=descriptions[i].resonance;
        filters[i]=new filter{useFilter,cutoff,resonance};
        effectType useEffect=descriptions[i].useEffect;
        double delay=descriptions[i].delay;
        double strength=descriptions[i].strength;
        effects[i]=new effect(samplerate,useEffect,delay,strength);
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
        delete filters[i];
        delete effects[i];
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
    // clearBuffer();

    for(int i=0;i<bufferSize;i++)
    {
        floatBuffer[i]=0;
        buffer[i]=0;
        
        for(int j=0;j<VOICES;j++)
        {
             channelFloatBuffers[j][i]=0;
            if(decoder.isStriked(j))
            {
                env->trigger(j,time);
            }
            double freq=decoder.getFreq(j,time);
            double subFreq=decoder.getFreq(j,time,true);
            double currentEnvVolume=env->getVolume(j,time)*env->getVolume(j,time);
            if(decoder.isfreqModulated(j))
            {
                freq*=currentEnvVolume;
                subFreq*=currentEnvVolume;
            }
                

            double wave;
            double currentTime=env->getCurrentTime(j,time);
            wave=chan.get(currentTime,decoder.getWaveform(j),freq)*decoder.getVolume(j);
            wave+=chan.get(currentTime,decoder.getSubWaveform(j),subFreq)*decoder.getSubVolume(j);
            wave*=env->getVolume(j,time);
            wave=filters[j]->getFiltered(wave);
            wave=effects[j]->getEffect(wave);

            channelFloatBuffers[j][i]=wave;
            floatBuffer[i]+=wave*.1;
            buffer[i]+=wave*4096*volume;
        }
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
