#ifndef DECODE
#define DECODE

#include "tetris_sng.h"

class decode
{
public:
    decode();
    int getChannelCnt();
    int getPatternSize();
    int getLength();
    double getVolume(int channel);
    int getWaveform(int channel);
    double getFreq(int channel, double time);
    bool isStriked(int channel);
    
private:
    char previous[VOICES];
    double volume[VOICES]{1.0};
    bool strike[VOICES]{true};
};

#endif//decode