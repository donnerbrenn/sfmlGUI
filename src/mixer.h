#ifndef MIXER
#define MIXER

#include <vector>
#include "channel.h"
#include "iostream"

class mixer
{
public:
    mixer(int channelCnt=1, int buffersize=1024, int samplerate=44100);
    ~mixer();
    short *getBufferPtr();
    int getBufferSize();
    void run();
    void setVolume(double value);
private:
    std::vector<channel> channels;
    short *buffer;
    int buffersize;
    int samplerate;
    bool setWaveform(int channel, int waveform);
    int getWaveform(int channel);
    
    void mix(short *a, short *b, int size);
    void clear();
    double volume;
};

#endif // MIXER