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
        switch (waveform)
        {
        case sine:
            /* code */
            break;

        case square:
            phase=getSquare(phase);
            break;

        case noise:
            phase=getNoise();
            break;

        case triangle:
            phase=getTriangle(phase);
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
        buffer[i]=short(phase*volume);
        time+=step;
    }    
}

short *channel::getBufferPtr()
{
    return buffer;
}

double channel::getSquare(double value)
{
    return(value>0?1.0:-1.0);
}

double channel::getTriangle(double value)
{
    return asin(value);
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