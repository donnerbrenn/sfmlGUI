#include "decode.h"

decode::decode()
{
    for(int i=0;i<VOICES;i++)
    {
        volume[i]=descriptions[i].volume;
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
    return descriptions[channel].waveform;
}

int decode::getNote(int channel, double time, int offset)
{
    int pos = time*SPEED*5;
    pos+=offset;
    char note = cpatterns[channel][(pos/PATTERNLENGTH)%LENGTH][pos%PATTERNLENGTH];
    return note;

}

double decode::getFreq(int channel, double time, bool getSub)
{
    int pos = time*SPEED*5;

    char note = cpatterns[channel][(pos/PATTERNLENGTH)%LENGTH][pos%PATTERNLENGTH];

if(!getSub)
{
    strike[channel]=false;
    if(note==0)
    {
        previousStrike[channel]=0;
    }
    else if(note!=0&&previousStrike[channel]!=note)
    {
        strike[channel]=true;
        previousStrike[channel]=note;
    }
}

    if (note == 0)
    {
        note=previous[channel];
    }

    previous[channel]=note;

    double freq=16.3516f;
    int modify=getSub?descriptions[channel].sub_modify:descriptions[channel].modify;
    for(int i=1;i<note+modify;++i)
    {
        freq*=1.05946;
    }
    return freq;    
}

bool decode::isStriked(int channel)
{
    return strike[channel];
}

bool decode::isfreqModulated(int channel)
{
    return descriptions[channel].freqModulate;
}

double decode::getSubVolume(int channel)
{
    return descriptions[channel].sub_volume;
}

double decode::getSubWaveform(int channel)
{
    return descriptions[channel].sub_waveform;
}
