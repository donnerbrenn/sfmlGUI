#ifndef CHANNEL
#define CHANNEL
#include "envelope.h"
#include <math.h>

enum waveform
{
    sine,
    triangle,
    square,
    saw,
    rsaw,
    noise
};

class channel
{
public:
    channel(double volume, int waveform=sine, int buffersize=1024, int samplerate=44100);
    void init(int waveform, int buffersize, int samplerate);
    ~channel();
    bool setWaveform(int waveform);
    int getWaveform();
    void run(double hertz);
    short *getBufferPtr();
    double getSquare(double value);
    double getTriangle(double value);
    double getSaw(double value);
    double getRsaw(double value);
    double getNoise();
    double getSine(double hertz);

private:
    double time;
    double step;
    double volume;
    int waveform;
    int bufferSize;
    short *buffer;
    int samplerate;
    double lastHz=0;
    double currentVol;
};

#endif //CHANNEL