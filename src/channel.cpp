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

void channel::run(double hertz)
{
    double phase;
    for(int i=0;i<bufferSize;i++)
    {
        phase=sin(hertz*M_PI*2*time);
        switch (waveform)
        {
        case sine:
            phase=getSine(hertz);
            break;

        case square:
            phase=getSquare(hertz);
            break;

        case noise:
            phase=getNoise();
            break;

        case triangle:
            phase=getTriangle(hertz);
            break;

        case saw:
            phase=getSaw(hertz);
            break;

        case rsaw:
            phase=getRsaw(hertz);
            break;

        default:
            break;
        }

        if(hertz!=lastHz)
        {
            currentVol=volume;
            time=0;
        }
        else
        {
            currentVol*=.9999;
        }
        lastHz=hertz;
        
        buffer[i]=short(phase*currentVol);
        time+=step;
    }    
}

short *channel::getBufferPtr()
{
    return buffer;
}

double channel::getSquare(double value)
{
    return(getSine(value)>0?1.0:-1.0);
}

double channel::getTriangle(double value)
{
    return asin(getSine(value));
}

double channel::getSaw(double value)
{
    return(2.0/M_PI)*(value*M_PI*fmod(time,1.0/value)-(M_PI/2.0));
}

double channel::getRsaw(double value)
{
    return(-getSaw(value));
}

double channel::getNoise()
{
    return((rand()%2000)*.001-1.0);
}

double channel::getSine(double hertz)
{
    return sin(hertz*M_PI*2*time);
}