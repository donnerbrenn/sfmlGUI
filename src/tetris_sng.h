#ifndef PATTERN_H
#define PATTERN_H
#define LENGTH 8
#define VOICES 4
#define SPEED 1.6
#define PATTERNLENGTH 64

#include "channel.h"

const bool muted[]={false,false,false,true};// true false

struct description
{
    int waveform=sine;
    double volume=.5;
    int modify=0;
    double a=.0;
    double d=.5;
    double s=.025;
    double r=.5;

    int sub_waveform=mute;
    double sub_volume=.25;
    int sub_modify=0;
};

const description snare
{
    .waveform=sine,
    .volume=3.0,
    .modify=-55,
    .a=.00,
    .d=.5,
    .s=.0,
    .r=.25,
    .sub_waveform=square,
    .sub_volume=.5,
    .sub_modify=-48
};

const description bass
{
    .waveform=triangle,
    .volume=.75,
    .modify=0,
    .a=.0,
    .d=3.0,
    .s=.05,
    .r=.5,
    .sub_waveform=square,
    .sub_volume=.5,
    .sub_modify=0
};

const description lead
{
    .waveform=square,
    .volume=.5,
    .modify=0,
    .a=.01,
    .d=2.0,
    .s=.1,
    .r=.5,
    .sub_waveform=triangle,
    .sub_volume=.15,
    .sub_modify=0
};

const description lead2
{
    .waveform=triangle,
    .volume=.350,
    .modify=0,
    .a=.05,
    .d=1.2,
    .s=.05,
    .r=.75,
    .sub_waveform=square,
    .sub_volume=.5,
    .sub_modify=0
};

const description descriptions[]=
{
    lead,
    lead2,
    bass,
    snare
};

const unsigned char cpatterns[VOICES][LENGTH][PATTERNLENGTH]=
{
    {
        {62,0,0,0,57,0,58,0,60,0,62,60,58,0,57,0,55,0,0,0,55,0,58,0,62,0,0,0,60,0,58,0,57,0,0,0,57,0,58,0,60,0,0,0,62,0,0,0,58,0,0,0,55,0,0,0,55,0,0,0,0,0,0,0},
        {0,0,60,0,0,0,63,0,67,0,0,0,65,0,63,0,62,0,0,0,0,0,58,0,62,0,63,62,60,0,58,0,57,0,0,0,57,0,58,0,60,0,0,0,62,0,0,0,58,0,0,0,55,0,0,0,55,0,0,0,0,0,0,0},
        {62,0,0,0,57,0,58,0,60,0,62,60,58,0,57,0,55,0,0,0,55,0,58,0,62,0,0,0,60,0,58,0,57,0,0,0,57,0,58,0,60,0,0,0,62,0,0,0,58,0,0,0,55,0,0,0,55,0,0,0,0,0,0,0},
        {0,0,60,0,0,0,63,0,67,0,0,0,65,0,63,0,62,0,0,0,0,0,58,0,62,0,63,62,60,0,58,0,57,0,0,0,57,0,58,0,60,0,0,0,62,0,0,0,58,0,0,0,55,0,0,0,55,0,0,0,0,0,0,0},
        {62,0,0,0,0,0,0,0,58,0,0,0,0,0,0,0,60,0,0,0,0,0,0,0,57,0,0,0,0,0,0,0,58,0,0,0,0,0,0,0,55,0,0,0,0,0,0,0,54,0,0,0,0,0,0,0,57,0,0,0,0,0,0,0},
        {62,0,0,0,0,0,0,0,58,0,0,0,0,0,0,0,60,0,0,0,0,0,0,0,57,0,0,0,0,0,0,0,58,0,0,0,62,0,0,0,67,0,0,0,0,0,0,0,66,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {62,0,0,0,57,0,58,0,60,0,62,60,58,0,57,0,55,0,0,0,55,0,58,0,62,0,0,0,60,0,58,0,57,0,0,0,57,0,58,0,60,0,0,0,62,0,0,0,58,0,0,0,55,0,0,0,55,0,0,0,0,0,0,0},
        {0,0,60,0,0,0,63,0,67,0,0,0,65,0,63,0,62,0,0,0,0,0,58,0,62,0,63,62,60,0,58,0,57,0,0,0,57,0,58,0,60,0,0,0,62,0,0,0,58,0,0,0,55,0,0,0,55,0,0,0,0,0,0,0}
    },
    {
        {57,0,0,0,54,0,55,0,57,0,0,0,55,0,54,0,50,0,0,0,50,0,55,0,58,0,0,0,57,0,55,0,54,0,50,0,54,0,55,0,57,0,0,0,58,0,0,0,55,0,0,0,50,0,0,0,50,0,0,0,0,0,0,0},
        {0,0,51,0,0,0,55,0,58,0,58,58,57,0,55,0,53,0,0,0,0,0,50,0,53,0,55,53,51,0,50,0,54,0,50,0,54,0,55,0,57,0,54,0,58,0,54,0,55,0,50,0,50,0,0,0,50,0,0,0,0,0,0,0},
        {57,0,0,0,54,0,55,0,57,0,0,0,55,0,54,0,50,0,0,0,50,0,55,0,58,0,0,0,57,0,55,0,54,0,50,0,54,0,55,0,57,0,0,0,58,0,0,0,55,0,0,0,50,0,0,0,50,0,0,0,0,0,0,0},
        {0,0,51,0,0,0,55,0,58,0,58,58,57,0,55,0,53,0,0,0,0,0,50,0,53,0,55,53,51,0,50,0,54,0,50,0,54,0,55,0,57,0,54,0,58,0,54,0,55,0,50,0,50,0,0,0,50,0,0,0,0,0,0,0},
        {58,0,0,0,0,0,0,0,55,0,0,0,0,0,0,0,57,0,0,0,0,0,0,0,54,0,0,0,0,0,0,0,55,0,0,0,0,0,0,0,50,0,0,0,0,0,0,0,50,0,0,0,0,0,0,0,54,0,0,0,0,0,0,0},
        {58,0,0,0,0,0,0,0,55,0,0,0,0,0,0,0,57,0,0,0,0,0,0,0,54,0,0,0,0,0,0,0,55,0,0,0,58,0,0,0,62,0,0,0,0,0,0,0,60,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {57,0,0,0,54,0,55,0,57,0,0,0,55,0,54,0,50,0,0,0,50,0,55,0,58,0,0,0,57,0,55,0,54,0,50,0,54,0,55,0,57,0,0,0,58,0,0,0,55,0,0,0,50,0,0,0,50,0,0,0,0,0,0,0},
        {0,0,51,0,0,0,55,0,58,0,58,58,57,0,55,0,53,0,0,0,0,0,50,0,53,0,55,53,51,0,50,0,54,0,50,0,54,0,55,0,57,0,54,0,58,0,54,0,55,0,50,0,50,0,0,0,50,0,0,0,0,0,0,0}
    },
    {
        {26,0,38,0,26,0,38,0,26,0,38,0,26,0,38,0,31,0,43,0,31,0,43,0,31,0,43,0,31,0,43,0,30,0,42,0,30,0,42,0,26,0,38,0,26,0,38,0,31,0,43,0,31,0,43,0,31,0,33,0,0,0,34,0},
        {36,0,24,0,0,0,24,0,0,0,24,0,31,0,24,0,22,0,34,0,0,0,34,0,22,0,29,0,29,0,0,0,33,0,45,0,0,0,45,0,0,0,38,0,0,0,42,0,31,0,38,0,31,0,38,0,31,0,0,0,0,0,0,0},
        {26,0,38,0,26,0,38,0,26,0,38,0,26,0,38,0,31,0,43,0,31,0,43,0,31,0,43,0,31,0,43,0,30,0,42,0,30,0,42,0,26,0,38,0,26,0,38,0,31,0,43,0,31,0,43,0,31,0,33,0,0,0,34,0},
        {36,0,24,0,0,0,24,0,0,0,24,0,31,0,24,0,22,0,34,0,0,0,34,0,22,0,29,0,29,0,0,0,33,0,45,0,0,0,45,0,0,0,38,0,0,0,42,0,31,0,38,0,31,0,38,0,31,0,0,0,0,0,0,0},
        {43,0,50,0,43,0,50,0,43,0,50,0,43,0,50,0,42,0,50,0,42,0,50,0,42,0,50,0,42,0,50,0,43,0,50,0,43,0,50,0,43,0,50,0,43,0,50,0,42,0,50,0,42,0,50,0,42,0,50,0,42,0,50,0},
        {43,0,50,0,43,0,50,0,43,0,50,0,43,0,50,0,42,0,50,0,42,0,50,0,42,0,50,0,42,0,50,0,43,0,50,0,43,0,50,0,43,0,50,0,43,0,50,0,42,0,50,0,42,0,50,0,42,0,0,0,50,0,0,0},
        {26,0,38,0,26,0,38,0,26,0,38,0,26,0,38,0,31,0,43,0,31,0,43,0,31,0,43,0,31,0,43,0,30,0,42,0,30,0,42,0,26,0,38,0,26,0,38,0,31,0,43,0,31,0,43,0,31,0,33,0,0,0,34,0},
        {36,0,24,0,0,0,24,0,0,0,24,0,31,0,24,0,22,0,34,0,0,0,34,0,22,0,29,0,29,0,0,0,33,0,45,0,0,0,45,0,0,0,38,0,0,0,42,0,31,0,38,0,31,0,38,0,31,0,0,0,0,0,0,0}
    },
    {
        {56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0},
        {56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0},
        {56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0},
        {56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0},
        {56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0},
        {56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0},
        {56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0},
        {56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0,56,0,0,0}
    }
};

#endif // PATTERN_H
