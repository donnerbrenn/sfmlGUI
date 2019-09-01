#pragma once
#include "element.h"
#include <vector>
#include "label.h"
#include "decode.h"

class noteDisplay:public element
{
public:
    noteDisplay(int x, int y, int rows, int channel):
    element(x,y,128,128,"",noteDisplay_type)
    {
        this->x=x;
        this->y=y;
        this->rows=rows;
        for(int i=0;i<rows;i++)
        {
            // label newLabel{x,y+i*20,"",false};
            // labels.emplace_back(newLabel);
        }
    }
    void draw(sf::RenderWindow *window);
    sf::String valueToNote(int value);
    void update(double time);


protected:
    int rows;
    int x;
    int y;
    int channel;

    decode decoder;
    std::vector<sf::String> labels;
    const sf::String noteNames[12]=
    {
        "C",
        "C#",
        "D",
        "D#",
        "E",
        "F",
        "F#",
        "G",
        "G#",
        "A",
        "A#",
        "H"
    };
};
