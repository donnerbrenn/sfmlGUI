#ifndef FRAME
#define FRAME

#include "element.h"
#include "defines.h"


class frame : public element
{
public:
    frame():element(){}
    frame(int x, int y, int w, int h, sf::String label=""):element(x,y,w,h,"bitmaps/frame.png",frame_type)
    {
        initCanvas(w,h);
    }
    virtual void draw(sf::RenderWindow *window);
};
#endif