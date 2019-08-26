#pragma once
#include "channel.h"
#include "filter.h"
#include "effect.h"

struct description
{
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

    effectType useEffect=noeEffect;
    double delay=.025;
    double strength=.5;
};

const description bassdrum
{
    .freqModulate=true,
    .waveform=sine,
    .volume=.75,
    .modify=16,
    .a=.01,
    .d=1.5,
    .s=.1,
    .r=.4,
    .sub_waveform=sine,
    .sub_volume=.15,
    .sub_modify=8,
    .useFilter=highstop,
    .cutoff=.99,
    .resonance=.9,
    // .useEffect=reverb,
    // .delay=.1,
    // .strength=.25
};

const description hihat
{
    .waveform=noise,
    .volume=.175,
    .modify=-6,
    .a=.00,
    .d=6.5,
    .s=.05,
    .r=.25,
    .sub_waveform=mute,
    .sub_volume=.005,
    .sub_modify=48,
    .useFilter=bandstop,
    .cutoff=.45,
    .resonance=.525,
};

const description bass
{
    .waveform=sine,
    .volume=.2,
    .modify=0,
    .a=.0,
    .d=2.0,
    .s=.025,
    .r=.5,
    .sub_waveform=rsaw,
    .sub_volume=.25,
    .sub_modify=0,
    .useFilter=highstop,
    .cutoff=.3,
    .resonance=.4,
    // .useEffect=reverb,
    // .delay=.125,
    // .strength=.5
};


const description lowbass
{
    .waveform=sine,
    .volume=.2,
    .modify=-0,
    .a=.0,
    .d=2.0,
    .s=.025,
    .r=.5,
    .sub_waveform=rsaw,
    .sub_volume=.5,
    .sub_modify=-0,
    .useFilter=bandstop,
    .cutoff=.05,
    .resonance=.5
};


const description lead
{
    .waveform=square,
    .volume=.2,
    .modify=0,
    .a=.0,
    .d=2.0,
    .s=.1,
    .r=1.0,
    .sub_waveform=rsaw,
    .sub_volume=.15,
    .sub_modify=0,
    .useFilter=highstop,
    .cutoff=.05,
    .resonance=.25,
    // .useEffect=reverb,
    // .delay=.125,
    // .strength=.0125
};

const description lead2
{
    .waveform=square,
    .volume=.1,
    .modify=0,
    .a=.0025,
    .d=1.8,
    .s=.25,
    .r=1.0,
    .sub_waveform=mute,
    .sub_volume=.15,
    .sub_modify=0,
    // .useFilter=highpass,
    // .cutoff=.05,
    // .resonance=.5,
    // .useEffect=reverb,
    // .delay=.025,
    // .strength=.1
};


const description lowlead
{
    .waveform=square,
    .volume=.2,
    .modify=-0,
    .a=.0,
    .d=2.0,
    .s=.1,
    .r=1.0,
    .sub_waveform=mute,
    .sub_volume=.15,
    .sub_modify=-48,
    .useFilter=bandstop,
    .cutoff=.05,
    .resonance=.5,
};

const description lowlead2
{
    .waveform=square,
    .volume=.2,
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
    .resonance=.5
};