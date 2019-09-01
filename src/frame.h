#pragma once
#include "element.h"
#include "defines.h"


class frame : public element
{
public:
    frame():element(){}
    frame(int x, int y, int w, int h, sf::String label="",sf::Color bgColor=sf::Color::Black):element(x,y,w,h,"bitmaps/frame.png",frame_type)
    {
        this->bgColor=bgColor;
        initCanvas(w,h);
    }
    virtual void draw(sf::RenderWindow *window);

private:
    sf::Color bgColor;
};