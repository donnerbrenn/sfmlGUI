#pragma once
#include "element.h"
#include "defines.h"


class frame : public element
{
public:
    frame():element(){}
    frame(int x, int y, int w, int h, sf::String label="",sf::Color bgColor=sf::Color(128,128,128), sf::Color fgColor=sf::Color::Black):
    element(x,y,w,h,"",frame_type)
    {
        this->fgColor=fgColor;
        this->bgColor=bgColor;
        initCanvas(w,h);

        border.setSize(sf::Vector2f(width,height));
        border.setFillColor(fgColor);
        border.setPosition(posX,posY);

        back.setSize(sf::Vector2f(width-4,height-4));
        back.setFillColor(bgColor);
        back.setPosition(posX+2,posY+2);
    }
    virtual void draw(sf::RenderWindow *window);

private:
    sf::Color bgColor;
    sf::Color fgColor;
    sf::RectangleShape border;
    sf::RectangleShape back;
};