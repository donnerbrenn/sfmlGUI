#pragma once

enum mode{none,highpass,lowpass,bandpass,highstop,lowstop,bandstop};

class filter
{
public:
    filter();
    filter(mode currentMode, double cutoff=.99, double resonance=0);
    ~filter();
    double getFiltered(double value);
    void setResonance(double value);
    void setCutoff(double value);
    double getResonance();
    double getCutoff();

private:
    mode currentMode;
    double cutoff=.99;
    double resonance=.0;
    double buf0=.0;
    double buf1=.0;
};