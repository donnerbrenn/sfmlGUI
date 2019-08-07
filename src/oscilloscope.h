#ifndef OSCILLOSCOPE
#define OSCILLOSCOPE

#include "frame.h"

class oscilloscope : public frame
{
public:
    oscilloscope():frame(){}
    oscilloscope(int x, int y, int w, int h, float *data, int size, float scale=1.0):
    frame(x,y,w,h,"")
    {
        this->scale=scale;
        this->data=data;
        this->size=size;
    }

    void draw(sf::RenderWindow *window);
    void setScale(float scale);
    float getScale();



protected:
    float *data;
    int size;
    float scale;
    void drawCurve();
};

#endif // OSCILLOSCOPE