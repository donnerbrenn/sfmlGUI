#pragma once
#include <SFML/Audio.hpp>
#include <vector>
#include "channel.h"
#include "decode.h"
#include "envelope.h"
#include "filter.h"
#include "effect.h"
#include <iostream>

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

    void setFilterCutoff(int channel, double value);
    void setFilterResonance(int channel, double value);
    void setEffectStrength(int channel, double value);
    void setEffectDelay(int channel, double value);

    void setEnvelopeA(int channel, double value);
    void setEnvelopeD(int channel, double value);
    void setEnvelopeS(int channel, double value);
    void setEnvelopeR(int channel, double value);

    void setInstrumentVolume(int channel, double value);
    void setInstrumentSubVolume(int channel, double value);

    void switchInstrumentMuted(int channel);
    void switchInstrumentSMuted(int channel);

    void setWaveform(int channel, osc waveform);
    void setSWaveform(int channel, osc waveform);
    void setFilter(int channel, mode flt);

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
    effect *effects[VOICES];
    double volumes[VOICES];
    double subvolumes[VOICES];
    bool muted[VOICES];
    bool smuted[VOICES];
    osc waveforms[VOICES];
    osc swaveforms[VOICES];
    mode modes[VOICES];
};