#pragma once
#include "label.h"
#include <sstream>

class noteLabel : public label
{
public:
    noteLabel(int x, int y, sf::String text="-",bool centered=true):
    label(x,y,text,centered)
    {

    }
    void setNote(int note);


protected:
    const std::string noteNames[12]=
    {
        "C-",
        "C#",
        "D-",
        "D#",
        "E-",
        "F-",
        "F#",
        "G-",
        "G#",
        "A-",
        "A#",
        "H-"
    };

};