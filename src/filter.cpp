#include "filter.h"
// #include <iostream>


filter::filter(mode currentMode, double cutoff, double resonance)
{
    this->currentMode=currentMode;
    this->cutoff=cutoff;
    this->resonance=resonance;
    calculateFeedbackAmount();
}
filter::~filter()
{

}

double filter::getFiltered(double value) 
{
    buf0 += cutoff * (value - buf0 + feedbackAmount * (buf0 - buf1));
    buf1 += cutoff * (buf0 - buf1);
    switch (currentMode) {
        case lowpass:
            return buf1;
        case highpass:
            return value - buf0;
        case bandpass:
            return buf0 - buf1;


        case lowstop:
            return value - buf1;
        case highstop:
            return value-(value-buf0);
        case bandstop:
            return value-(buf0-buf1);
        default:
            return value;
    }
}

void filter::setResonance(double value)
{
    this->resonance=value;
    calculateFeedbackAmount();
}

void filter::setCutoff(double value)
{
    this->cutoff=value;
    calculateFeedbackAmount();
}

double filter::getResonance()
{
    return resonance;
}
double filter::getCutoff()
{
    return cutoff;
}

void filter::calculateFeedbackAmount() 
{
    feedbackAmount = resonance + resonance/(1.0 - cutoff);
}
