#pragma once
#include <SFML/Audio.hpp>
#include <vector>
#include "channel.h"
#include "decode.h"
#include "envelope.h"
#include "filter.h"

class synth : public sf::SoundStream
{
public:
    synth(int channels=1,int bufferSize=1024,int samplerate=44100, double volume=1.0);
    ~synth();
    short *getBufferPtr();
    float *getFloatBufferPtr();
    float *getChannelFloatBuffer(int channel);
    void setVolume(double volume);
    float getVolume();

private:
    bool onGetData(Chunk& data);
    void onSeek(sf::Time timeOffset); 
    void clearBuffer();

    short *buffer;
    float *floatBuffer;
    double volume;
    int channelCnt;
    int bufferSize;
    int samplerate;
    double time;
    channel chan;
    decode decoder;
    envelope *env;
    float *channelFloatBuffers[VOICES];
    filter *filters[VOICES];
};