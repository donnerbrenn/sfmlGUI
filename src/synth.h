#ifndef SYNTH
#define SYNTH
#include <SFML/Audio.hpp>
#include <vector>
#include "channel.h"
#include "decode.h"

class synth : public sf::SoundStream
{
public:
    synth(int channels=1,int bufferSize=1024,int samplerate=44100, double volume=1.0);
    ~synth();
    short *getBufferPtr();
    float *getFloatBufferPtr();
    void setVolume(double volume);

private:
    bool onGetData(Chunk& data);
    void onSeek(sf::Time timeOffset); 
    void clearBuffer();
    void convertShortToFloatBuffer();

    short *buffer;
    float *floatBuffer;
    double volume;
    int channelCnt;
    int bufferSize;
    int samplerate;
    double time;
    channel chan;
    decode decoder;

    
};


#endif //SYNTH