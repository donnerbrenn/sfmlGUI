#ifndef OSCILLOSCOPE
#define OSCILLOSCOPE

#include "frame.h"



class oscilloscope : public frame
{
public:
    oscilloscope():frame(){}
    oscilloscope(int x, int y, int w, int h, float *data, int size, float scale=1.0, sf::Color bgColor=sf::Color::Black, sf::Color fgColor=sf::Color::White):
    frame(x,y,w,h,"")
    {
        this->fgColor=fgColor;
        this->bgColor=bgColor;
        this->scale=scale;
        this->data=data;
        this->size=size;
        this->type=oscilloscope_type;
    }

    void draw(sf::RenderWindow *window);
    void setScale(float scale);
    float getScale();
    void setBgColor(sf::Color col);
    void setFgColor(sf::Color col);
    sf::Color getBgColor();
    sf::Color getFgColor();



protected:
    sf::Color fgColor;
    sf::Color bgColor;
    sf::RenderStates states;
    float *data;
    int size;
    float scale;
    void drawCurve();
};

#endif // OSCILLOSCOPE
