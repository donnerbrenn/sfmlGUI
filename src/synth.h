#ifndef SYNTH
#define SYNTH
#include <SFML/Audio.hpp>
#include "mixer.h"

class synth:public sf::SoundStream
{
public:
    synth(int channels=1,int buffersize=1024,int samplerate=44100, double volume=1.0);
    short *getBufferPtr();
    void setVolume(float volume);
private:
    bool onGetData(Chunk& data);
    void onSeek(sf::Time timeOffset);

private:
    mixer mix;
};

#endif //SYNTH