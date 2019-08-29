#include "effect.h"
#include <iostream>

effect::effect(int samplerate, effectType type, double buffersize, double strength, int iterations)
{
    if(type==noEffect)
        buffersize=0;
    this->strength=strength;
    this->type=type;
    this->buffersize=buffersize/(1.0/samplerate);
    this->buffer=new double[this->buffersize];
    this->currentIDX=0;
    this->iterations=iterations;
    std::cout << buffersize << " " << this->buffersize << "\n";
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
    currentIDX++;
    currentIDX=getRingbufferIDX(currentIDX);
    buffer[currentIDX]=value;

    // for(int i=0;i<iterations;i++)
    // {
        
    // }
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