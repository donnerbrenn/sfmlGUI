#ifndef CHANNEL
#define CHANNEL
#include "envelope.h"
#include <math.h>

enum waveform
{
    sine,
    triangle,
    saw,
    rsaw,
    noise
};

class channel
{
public:
    channel(int waveform=sine, int buffersize=1024, int samplerate=44100);
    void init(int waveform, int buffersize, int samplerate);
    ~channel();
    bool setWaveform(int waveform);
    int getWaveform();
    void run();
    short *getBufferPtr();

private:
    double time;
    double step;
    double volume=1024;
    int waveform;
    int bufferSize;
    short *buffer;
    int samplerate;

};

#endif //CHANNEL