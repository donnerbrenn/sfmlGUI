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
        this->muted[i]=false;
        this->smuted[i]=false;
        this->waveforms[i]=osc(decoder.getWaveform(i));
        this->swaveforms[i]=osc(decoder.getSubWaveform(i));
        volumes[i]=decoder.getVolume(i);
        subvolumes[i]=decoder.getSubVolume(i);
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
            if(!this->muted[j])
            {
                wave=chan.get(currentTime,waveforms[j],freq)*volumes[j];
                 if(!this->smuted[j])
                {
                    wave+=chan.get(currentTime,swaveforms[j],subFreq)*subvolumes[j];
                }
                wave*=volumes[j];
                wave*=env->getVolume(j,time);
                wave=filters[j]->getFiltered(wave);
                wave=effects[j]->getEffect(wave);
                channelFloatBuffers[j][i]=wave*.5;
                // floatBuffer[i]+=wave*.1;
                buffer[i]+=wave*4096*volume;
            }

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

void synth::setFilterCutoff(int channel, double value)
{
    filters[channel]->setCutoff(value);
    
}

void synth::setFilterResonance(int channel, double value)
{
    filters[channel]->setResonance(value);
}

void synth::setEffectStrength(int channel, double value)
{
    effects[channel]->setStrength(value);
}

void synth::setEffectDelay(int channel, double value)
{
    effects[channel]->setDelay(value);
}

void synth::setEnvelopeA(int channel, double value)
{
    env->setEnvelopeA(channel,value);
}

void synth::setEnvelopeD(int channel, double value)
{
    env->setEnvelopeD(channel,value);
}

void synth::setEnvelopeS(int channel, double value)
{
    env->setEnvelopeS(channel,value);
}

void synth::setEnvelopeR(int channel, double value)
{
    env->setEnvelopeR(channel,value);
}

void synth::setInstrumentVolume(int channel, double value)
{
    volumes[channel]=value;
}


void synth::setInstrumentSubVolume(int channel, double value)
{
    subvolumes[channel]=value;
}

void synth::switchInstrumentMuted(int channel)
{
    if(muted[channel])
    {
        muted[channel]=false;
    }
    else
    {
        muted[channel]=true;
    }
}

void synth::switchInstrumentSMuted(int channel)
{
    if(smuted[channel])
    {
        smuted[channel]=false;
    }
    else
    {
        smuted[channel]=true;
    }
}

void synth::setWaveform(int channel, osc waveform)
{
    waveforms[channel]=waveform;
}

void synth::setSWaveform(int channel, osc waveform)
{
    swaveforms[channel]=waveform;
}

void synth::setFilter(int channel, mode flt)
{
    filters[channel]->setFilter(flt);
}