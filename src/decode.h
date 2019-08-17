#ifndef DECODE
#define DECODE
#include "tetris_sng.h"

class decode
{
public:
    decode();
    double run(double time, int channel);
    double getFrq(int note);
    int getChannelCnt();
    int getPatternCnt();
    int getPatternLen();
    int getWaveForm(int channel);
    double getVolume(int channel);

private:
    double speed=1.0;
    char previous=0;
};

#endif // DECODE