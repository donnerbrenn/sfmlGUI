#ifndef KNOB
#define KNOB

#include "element.h"
#include "defines.h"
#include "iostream"

class knob : public element
{
public:
    knob():element(){}
    knob(int x, int y, sf::String label="Knob", int w=64, int h=64):element(x,y,w,h,"bitmaps/knob.png",knob_type)
    {
        setValue(value);
        this->overlayFileName="bitmaps/tick.png";
        initOverlay(x,y);
        initLabel(0,50,label);
        initDisplay(0,68);
    }
    void draw(sf::RenderWindow *window);
    void setValue(float value);
    float getValue();
    void update();
    void pressAction();
    void releaseAction();
    void moveAction(float delta, sf::RenderWindow *window);
    void setMin(float value);
    void setMax(float value);
    float getMin();
    float getMax();
    float getRange();

protected:
    float value;
    bool isPressed=false;
    sf::Vector2i lastPos;
    int minimum=0;
    int maximum=100;
    sf::Text display;

    void initDisplay(int x, int y);
};
#endif