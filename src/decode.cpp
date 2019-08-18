#include "decode.h"

decode::decode()
{
    for(int i=0;i<VOICES;i++)
    {
        volume[i]=volumes[i];
    }
}

int decode::getChannelCnt()
{
    return VOICES;
}

int decode::getPatternSize()
{
    return PATTERNLENGTH;
}

int decode::getLength()
{
    return LENGTH;
}

double decode::getVolume(int channel)
{
    return volume[channel];
}

int decode::getWaveform(int channel)
{
    return waveforms[channel];
}

double decode::getFreq(int channel, double time)
{
    int pos = time*SPEED*5;

    char note = cpatterns[channel][(pos>>6)&7][pos&63];
    if (note == 0 || note==previous[channel])
    {
        note=previous[channel];
        strike[channel]=false;
    }
    else if (note != previous[channel])
    {
        strike[channel]=true;
    }
    else
    {
        strike[channel]=true;
    }
    
   
    previous[channel]=note;

    double freq=16.3516f;
    for(int i=1;i<note+modify[channel];++i)
    {
        freq*=1.05946;
    }
    return freq;
}

bool decode::isStriked(int channel)
{
    return strike[channel];
}