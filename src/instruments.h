#pragma once
#include "channel.h"
#include "filter.h"
#include "effect.h"
#include <SFML/System.hpp>

struct description
{
    sf::String name="Undefined";
    bool freqModulate=false;
    osc waveform=sine;
    double volume=.5;
    int modify=0;
    double a=.0;
    double d=.5;
    double s=.025;
    double r=.5;

    osc sub_waveform=mute;
    double sub_volume=.25;
    int sub_modify=0;

    mode useFilter=noFilter;
    double cutoff=.99;
    double resonance=.0;

    effectType useEffect=noEffect;
    double delay=.025;
    double strength=.5;
};

const description bassdrum
{
    .name="Bassdrum",
    .freqModulate=true,
    .waveform=sine,
    .volume=1.0,
    .modify=16,
    .a=.01,
    .d=2.0,
    .s=.1,
    .r=.4,
    .sub_waveform=sine,
    .sub_volume=.15,
    .sub_modify=0,
    .useFilter=lowpass,
    .cutoff=.99,
    .resonance=.9,
    .useEffect=reverb,
    .delay=.0,
    .strength=.25
};

const description hihat
{
    .name="Hihat",
    .waveform=noise,
    .volume=.5,
    .modify=-6,
    .a=.00,
    .d=6.5,
    .s=.05,
    .r=.25,
    .sub_waveform=sine,
    .sub_volume=.1,
    .sub_modify=0,
    .useFilter=bandpass,
    .cutoff=.45,
    .resonance=.8,
    .useEffect=reverb,
    .delay=.125,
    .strength=.125
};

const description bass
{
    .name="Bass",
    .waveform=square,
    .volume=.75,
    .modify=0,
    .a=.0,
    .d=2.0,
    .s=.025,
    .r=.5,
    .sub_waveform=triangle,
    .sub_volume=.25,
    .sub_modify=0,
    .useFilter=lowpass,
    .cutoff=.075,
    .resonance=.4,
    .useEffect=reverb,
    .delay=.125,
    .strength=.5
};


const description lowbass
{
    .name="Low Bass",
    .waveform=sine,
    .volume=.05,
    .modify=-12,
    .a=.0,
    .d=2.0,
    .s=.025,
    .r=.5,
    .sub_waveform=rsaw,
    .sub_volume=.5,
    .sub_modify=0,
    .useFilter=highstop,
    .cutoff=.05,
    .resonance=.0,
    .useEffect=reverb,
    .delay=.125*.5,
    .strength=.6
};


const description lead
{
    .name="Lead Synth",
    .waveform=saw,
    .volume=.75,
    .modify=0,
    .a=.0,
    .d=2.0,
    .s=.1,
    .r=.5,
    .sub_waveform=sine,
    .sub_volume=.15,
    .sub_modify=0,
    .useFilter=highpass,
    .cutoff=.05,
    .resonance=.3,
    .useEffect=reverb,
    .delay=.125,
    .strength=.6
};

const description lead2
{
    .name="Lead Synth 2",
    .waveform=square,
    .volume=.75,
    .modify=0,
    .a=.0,
    .d=1.8,
    .s=.0,
    .r=1.25,
    .sub_waveform=sine,
    .sub_volume=.15,
    .sub_modify=0,
    .useFilter=highpass,
    .cutoff=.05,
    .resonance=.3,
    .useEffect=reverb,
    .delay=.0,
    .strength=.60
};



const description lowlead
{
    .name="Low Lead",
    .waveform=square,
    .volume=.75,
    .modify=-0,
    .a=.0,
    .d=2.0,
    .s=.1,
    .r=1.0,
    .sub_waveform=mute,
    .sub_volume=.15,
    .sub_modify=0,
    .useFilter=bandstop,
    .cutoff=.05,
    .resonance=.5,
    .useEffect=reverb,
    .delay=.125
};

const description lowlead2
{
    .name="Low Lead 2",
    .waveform=square,
    .volume=.75,
    .modify=-12,
    .a=.025,
    .d=1.8,
    .s=.25,
    .r=1.0,
    .sub_waveform=mute,
    .sub_volume=.15,
    .sub_modify=0,
    .useFilter=highpass,
    .cutoff=.05,
    .resonance=.5,
    .useEffect=reverb,
    .delay=.125
};