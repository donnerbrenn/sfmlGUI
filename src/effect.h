#pragma once

enum effectType{noEffect=0,echo,reverb};


class effect
{
public:
    effect(int samplerate, effectType type, double buffersize, double strength, int iterations=1);
    ~effect();
    int getRingbufferIDX(int IDX);
    double getEffect(double value);

private:
    effectType type;
    int buffersize;
    int currentIDX;
    double *buffer;
    double strength;
    int iterations;
    double getReverb(double value);
    
};