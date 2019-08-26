#pragma once

enum effectType{noeEffect=0,echo,reverb};


class effect
{
public:
    effect(int samplerate, effectType type, double buffersize, double strength);
    ~effect();
    int getRingbufferIDX(int IDX);
    double getEffect(double value);

private:
    effectType type;
    int buffersize;
    int currentIDX;
    double *buffer;
    double strength;
    double getReverb(double value);
    
};