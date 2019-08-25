#pragma once

#include <math.h>

 enum osc{sine,triangle,square,saw,rsaw,noise, mute};


class channel
{
public:
    channel(int samplerate=44100, double volume=1.0);
    ~channel();
    double get(double time, int waveform, double hertz);
    double getSine(double time, double hertz);
    double getTriangle(double time, double hertz);
    double getSquare(double time, double hertz);
    double getSaw(double time, double hertz);
    double getRSaw(double time, double hertz);
    double getNoise();

private:
    double volume;
    int samplerate;
};
