#pragma once
<<<<<<< HEAD
#include "defines.h"
#include SONG
=======
#include "tetris_sng.h"
>>>>>>> 62af46f569aff92a021bb6157b41f5789dc6e96b
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
    bool isfreqModulated(int channel);
    bool isStriked(int channel);
    
    double getSubVolume(int channel);
    double getSubWaveform(int channel);

private:
    char previous[VOICES];
    char previousStrike[VOICES];
    double volume[VOICES]{1.0};
    bool strike[VOICES]{true};
};
