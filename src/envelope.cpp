#include "envelope.h"

envelope::envelope(int channels)
{
    start=new double[channels];
    a=new double[channels];
    d=new double[channels];
    s=new double[channels];
    r=new double[channels];

    for(int i=0;i<channels;i++)
    {
        start[i]=0;
        a[i]=.0025;
        d[i]=1.0;
        s[i]=.025;
        r[i]=.8;
    }
}

envelope::~envelope()
{
    delete[] start;
    delete[]a;
    delete[]d;
    delete[]s;
    delete[]r;
}

void envelope::trigger(int channel, double time)
{
    start[channel]=time;
}

double envelope::getVolume(int channel, double time)
{

    double currentTime=time-start[channel];
    if(currentTime<=a[channel])
    {
        return currentTime/a[channel]*d[channel];
    }
    else if(currentTime>a[channel]&&currentTime<=a[channel]+s[channel])
    {
        double overhead=d[channel]-1.0;
        double sustainTime=currentTime-a[channel];
        double currentOverhead=overhead*sustainTime/s[channel];
        return 1.0+currentOverhead;
    }
    else if (currentTime>a[channel]+s[channel]&&currentTime<=(a[channel]+s[channel]+r[channel]))
    {
        double releaseTime=currentTime-a[channel]-s[channel];
        return 1.0-(releaseTime/r[channel]);
    }
    return 0.0;
}

double envelope::getCurrentTime(int channel, double time)
{
    return time-start[channel];
}