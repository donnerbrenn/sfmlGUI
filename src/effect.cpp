#include "effect.h"
// #include <iostream>

effect::effect(int samplerate, effectType type, double delay, double strength, int iterations)
{
    this->delay=delay;
    this->samplerate=samplerate;
    if(type==noEffect)
        delay=0;
    this->strength=strength;
    this->type=type;
    this->buffersize=delay/(1.0/samplerate);
    this->buffer=new double[samplerate];
    this->currentIDX=0;
    this->iterations=iterations;
}

effect::~effect()
{
    delete[] buffer;
}

int effect::getRingbufferIDX(int IDX)
{
    if(IDX>=0)
    {
        return IDX%buffersize;
    }
    else
    {
        IDX=-IDX;
        IDX%=buffersize;;
        return getRingbufferIDX(buffersize-IDX);
    }  
}

double effect::getReverb(double value)
{
    if(buffersize==0)
        return value;

    currentIDX++;
    currentIDX=getRingbufferIDX(currentIDX);
    buffer[currentIDX]=value;
    int reverbIDX=getRingbufferIDX(currentIDX+1);
    return value+(buffer[reverbIDX]*strength);
}


double effect::getEffect(double value)
{
    switch (type)
    {
    case reverb:
        return getReverb(value);
    }
    return value;
}

void effect::setStrength(double value)
{
    strength=value;
}

void effect::setDelay(double value)
{
    this->buffersize=value/(1.0/samplerate);
}