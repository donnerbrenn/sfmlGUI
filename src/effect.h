#pragma once

enum effectType{noEffect=0,echo,reverb};

class effect
{
public:
    effect(int samplerate, effectType type, double delay, double strength, int iterations=1);
    ~effect();
    int getRingbufferIDX(int IDX);
    double getEffect(double value);
    void setStrength(double value);
    void setDelay(double value);
    void clear();

private:
    double delay;
    effectType type;
    int buffersize;
    int currentIDX;
    double *buffer;
    double strength;
    int iterations;
    double getEcho(double value);
    double getReverb(double value);
    int samplerate;
};