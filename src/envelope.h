#pragma once
// #include <iostream>
#include "defines.h"
#include SONG

class envelope
{
public:
    envelope(int channels);
    ~envelope();
    void trigger(int channel, double time);
    double getVolume(int channel, double time);
    double getCurrentTime(int channel, double time);
    void setEnvelopeA(int channel, double value);
    void setEnvelopeD(int channel, double value);
    void setEnvelopeS(int channel, double value);
    void setEnvelopeR(int channel, double value);

private:
    int samplerate;
    double *start;
    double *a;
    double *d;
    double *s;
    double *r;
};
