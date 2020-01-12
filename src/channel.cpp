#include "channel.h"

channel::channel(int samplerate, double volume)
{
    this->samplerate=samplerate;
    this->volume=volume;
}
channel::~channel()
{
}

double channel::get(double time, int waveform, double hertz)
{
    double result;
    switch (waveform)
    {
    case sine:
        result=getSine(time,hertz);
        break;
    case square:
        result=getSquare(time,hertz);
        break;
    case triangle:
        result=getTriangle(time,hertz);
        break;
    case saw:
        result=getSaw(time,hertz);
        break;
    case rsaw:
        result=getRSaw(time,hertz);
        break;
    case noise:
        result=getNoise();
        break;
    default:
        return 0;
    }
    return result;
}

double channel::approxsin(float x)
{
    double t=x*.15915;
    t=t-(int)t;
    if(t<.5)
        return(-16.0*t*t)+(8.0*t);
    else
    {
        return(16.0*t*t)-(16.0*t)-(8.0*t)+8.0;
    }
    
}

double  channel::getSine(double time, double hertz)
{
    return approxsin(hertz*M_PI*2*time);
}

double channel::getTriangle(double time, double hertz)
{
    return(asinf32(getSine(time,hertz)))*.75;
}

double channel::getSquare(double time, double hertz)
{
    return getSine(time,hertz)>0?1.0:-1.0;
}

double channel::getSaw(double time, double hertz)
{
    return(2.0/M_PI)*(hertz*M_PI*fmod(time,1.0/hertz)-(M_PI/2.0));
}

double channel::getRSaw(double time, double hertz)
{
    return -getSaw(time,hertz);
}


double channel::getNoise()
{
    return (rand()%32768-(32768/2))/32768.0;
}