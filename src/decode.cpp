#include "decode.h"

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
    return volumes[channel];
}

int decode::getWaveform(int channel)
{
    return waveforms[channel];
}

double decode::getFreq(int channel, double time)
{
    int pos = time*SPEED*5;

    char note = cpatterns[channel][(pos>>6)&7][pos&63];
    if (note == 0)
    {
        note=previous[channel];
    }
   
    previous[channel]=note;

    double freq=16.3516f;
    for(int i=1;i<note;++i)
    {
        freq*=1.05946;
    }
    return freq;
}