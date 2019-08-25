#pragma once

enum mode{none,highpass,lowpass,bandpass,highstop,lowstop,bandstop};

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

private:
    mode currentMode;
    double cutoff;
    double resonance;
    double buf0;
    double buf1;
    double feedbackAmount;
    void calculateFeedbackAmount();
};