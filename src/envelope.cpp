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
        a[i]=descriptions[i].a;
        d[i]=descriptions[i].d;
        s[i]=descriptions[i].s;
        r[i]=descriptions[i].r;
        
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
    double a_time=time-start[channel];
    double s_time=a_time-a[channel];
    double r_time=a_time-a[channel]-s[channel];

    if(a_time<=a[channel])
    {
        if(a[channel]!=0)
        {
            double result=a_time/a[channel];
            result*=result;
            return result*d[channel];
        }
        return 0;
    }

    if(s_time <= s[channel])
    {
        double overhead=d[channel]-1.0;
        double currentOverhead=(overhead*s_time/s[channel]);
        return 1.0+(overhead-currentOverhead);
    }

    if(r_time<=r[channel] && r_time >0)
    {
        double result=1.0-(r_time/r[channel]);
        return  result*result;
    }
    return 0.0;
}

double envelope::getCurrentTime(int channel, double time)
{
    return time-start[channel];
}