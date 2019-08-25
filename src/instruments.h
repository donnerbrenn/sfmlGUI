
#include "channel.h"
#include "filter.h"


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

    mode addFilter=none;
    double cutoff=.99;
    double resonance=.0;
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
    .addFilter=lowpass,
    .cutoff=.04,
    .resonance=.9
};

const description hihat
{
    .waveform=noise,
    .volume=.125,
    .modify=-6,
    .a=.00,
    .d=6.5,
    .s=.05,
    .r=.25,
    .sub_waveform=square,
    .sub_volume=.05,
    .sub_modify=-24,
    .addFilter=highpass,
    .cutoff=.55,
    .resonance=.5
};

const description bass
{
    .waveform=sine,
    .volume=.3,
    .modify=0,
    .a=.0,
    .d=2.0,
    .s=.025,
    .r=.5,
    .sub_waveform=square,
    .sub_volume=.5,
    .sub_modify=0,
    .addFilter=lowpass,
    .cutoff=.1,
    .resonance=.4
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
    .addFilter=highpass,
    .cutoff=.05,
    .resonance=.5
};

const description lead2
{

    .waveform=square,
    .volume=.2,
    .modify=0,
    .a=.075,
    .d=1.8,
    .s=.25,
    .r=1.0,
    .sub_waveform=triangle,
    .sub_volume=.15,
    .sub_modify=0,
    .addFilter=highpass,
    .cutoff=.05,
    .resonance=.5
};