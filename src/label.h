#pragma once
#include "element.h"


class label : public element
{
public:
    label() : element(){}
    label(int x, int y, sf::String text="EMPTY",bool centered=false):
    element(x, y, 0, 0, "", label_type)
    {
        init(x,y,text,centered);
    }

    label(int x, int y, float value,bool centered=false):
    element(x, y, 0, 0, "", label_type)
    {
        init(x,y,ftoa(value),centered);
    }

    label(int x, int y, int value,bool centered=false):
    element(x, y, 0, 0, "", label_type)
    {
        init(x,y,itoa(value),centered);
    }

    void init(int x, int y, sf::String text="EMPTY",bool centered=false);
    void draw(sf::RenderWindow *window);
    void initLabel(int x, int y, sf::String text);
    void setText(sf::String text);
    void setInt(int value);
    void setFloat(float value);

protected:
    bool centered;


};