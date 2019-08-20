#ifndef DECODE
#define DECODE

#include "tetris_sng.h"
#include <iostream>

class decode
{
public:
    decode();
    int getChannelCnt();
    int getPatternSize();
    int getLength();
    double getVolume(int channel);
    
    int getWaveform(int channel);
    double getFreq(int channel, double time, bool getSub=false);
    bool isStriked(int channel);
    
    double getSubVolume(int channel);
    double getSubWaveform(int channel);

private:
    char previous[VOICES];
    char previousStrike[VOICES];
    double volume[VOICES]{1.0};
    bool strike[VOICES]{true};
};

#endif//decode