#ifndef OSCILLOSCOPE
#define OSCILLOSCOPE

#include "frame.h"
#include "iostream"

enum partition{all,left,right};

class oscilloscope : public frame
{
public:
    oscilloscope():frame(){}
    oscilloscope(int x, int y, int w, int h, float *data, int size, bool dualBuffered, float scale=1.0, sf::Color bgColor=sf::Color::Black, sf::Color fgColor=sf::Color::White):
    frame(x,y,w,h,"")
    {
        this->canvas.setSmooth(true);
        this->fgColor=fgColor;
        this->bgColor=bgColor;
        this->scale=scale;
        this->data=data;
        this->size=size;
        this->type=oscilloscope_type;
        this->partition=dualBuffered;
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
    int partition;
};

#endif // OSCILLOSCOPE
