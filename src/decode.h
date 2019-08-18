#ifndef DECODE
#define DECODE

#include "tetris_sng.h"

class decode
{
public:
    int getChannelCnt();
    int getPatternSize();
    int getLength();
    double getVolume(int channel);
    int getWaveform(int channel);
    double getFreq(int channel, double time);
    char previous[VOICES];
    double prevTime[VOICES];


private:

};

#endif//decode