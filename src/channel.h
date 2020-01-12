#pragma once

#include <math.h>

 enum osc{mute=0,sine=1,triangle=2,square=3,saw=4,rsaw=5,noise=6};



class channel
{
public:
    channel(int samplerate=44100, double volume=1.0);
    ~channel();
    double get(double time, int waveform, double hertz);
    double approxsin(float t);
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
