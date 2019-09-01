#pragma once
#include "element.h"
#include "defines.h"


class frame : public element
{
public:
    frame():element(){}
    frame(int x, int y, int w, int h, sf::String label="",sf::Color bgColor=sf::Color(128,128,128), sf::Color fgColor=sf::Color::Black):
    element(x,y,w,h,"bitmaps/frame.png",frame_type)
    {
        this->fgColor=fgColor;
        this->bgColor=bgColor;
        initCanvas(w,h);
    }
    virtual void draw(sf::RenderWindow *window);

private:
    sf::Color bgColor;
    sf::Color fgColor;
};