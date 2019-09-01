#pragma once
#include <math.h>

enum mode{noFilter,highpass,lowpass,bandpass,highstop,lowstop,bandstop};

class filter
{
public:
    filter(mode currentMode, double cutoff=.03, double resonance=.0);
    ~filter();
    double getFiltered(double value);
    void setResonance(double value);
    void setCutoff(double value);
    double getResonance();
    double getCutoff();
    void setFilter(mode flt);

private:
    mode currentMode;
    double cutoff;
    double resonance;
    double buf0=0;
    double buf1=0;
    double buf2=0;
    double buf3=0;
    double feedbackAmount;
    void calculateFeedbackAmount();
    double min(double a, double b);
};