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

synth::synth(int channels,int buffersize,int samplerate, double volume)
{
    initialize(1,samplerate);
    mix=*new mixer(buffersize,samplerate);
    setVolume(volume);
}

short *synth::getBufferPtr()
{
    return mix.getBufferPtr();
}

void synth::setVolume(float volume)
{
    mix.setVolume(volume);
}