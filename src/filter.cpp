#include "filter.h"
#include <iostream>

filter::filter()
{
    this->currentMode=none;
}

filter::filter(mode currentMode, double cutoff, double resonance)
{
    this->currentMode=currentMode;
    this->cutoff=cutoff;
    this->resonance=resonance;
    buf0=0;
    buf1=0;
    std::cout << currentMode << "\n";
}
filter::~filter()
{

}
double filter::getFiltered(double value)
{
    buf0+=cutoff*(value-buf0);
    buf1+=cutoff*(buf0-buf1);
    switch (currentMode)
    {
        case none:
            return value;
            break;
        case highpass:
            return value-buf0;
            break;
        case bandpass:
            return buf0-buf1;
            break;
        case lowpass:
            return buf1;
            break;
        // case highstop:
        //     return highstopFilter(value);
        //     break;
        // case bandstop:
        //     return bandstopFilter(value);
        //     break;
        // case lowstop:
        //     return lowstopFilter(value);
        //     break;
    }
    return value;
}

void filter::setResonance(double value)
{
    this->resonance=value;
}

void filter::setCutoff(double value)
{
    this->cutoff=value;
}

double filter::getResonance()
{
    return resonance;
}
double filter::getCutoff()
{
    return cutoff;
}
