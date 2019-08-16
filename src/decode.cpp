#include "decode.h"

decode::decode()
{

}

double decode::run(double time, int channel)
{
    int pos = time*SPEED*5000;
    
    char note = cpatterns[channel][(pos>>6)&7][pos&63];
    if (note == 0)
    {
        note=previous;
    }
    previous=note;
    return getFrq(note);
}

double decode::getFrq(int note)
{
    double freq=16.3516f;
    for(int i=1;i<note;++i)
    {
        freq*=1.05946;
    }
    return freq;
}

int decode::getChannelCnt()
{
    return VOICES;
}

int decode::getPatternCnt()
{
    return LENGTH;
}

int decode::getPatternLen()
{
    return PATTERNLENGTH;
}

int decode::getWaveForm(int channel)
{
    return waveforms[channel];
}