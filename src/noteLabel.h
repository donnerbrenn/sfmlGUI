#pragma once
#include "label.h"
#include <sstream>

class noteLabel : public label
{
public:
    noteLabel(int x, int y, sf::String text="-",sf::Color color=sf::Color::White, bool centered=true):
    label(x,y,text,centered)
    {
        this->text.setFillColor(color);
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