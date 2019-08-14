#include "synth.h"

bool synth::onGetData(Chunk& data)
{
    mix.run();
    data.samples=mix.getBufferPtr();
    data.sampleCount=mix.getBufferSize();
    return true;    
}

void synth::onSeek(sf::Time timeOffset)
{

}

synth::synth(int channels,int buffersize,int samplerate)
{
    initialize(1,samplerate);
    mixer newMixer{channels,buffersize,samplerate};
    mix=newMixer;
}