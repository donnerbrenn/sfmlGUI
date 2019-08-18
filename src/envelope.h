#ifndef ENVELOPE
#define ENVELOPE
#include <iostream>
#include "tetris_sng.h"

class envelope
{
public:
    envelope(int channels);
    ~envelope();
    void trigger(int channel, double time);
    double getVolume(int channel, double time);
    double getCurrentTime(int channel, double time);

private:
    int samplerate;
    double *start;
    double *a;
    double *d;
    double *s;
    double *r;
};


#endif//ENVELOPE