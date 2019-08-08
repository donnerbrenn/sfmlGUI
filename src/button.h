
#ifndef BUTTON
#define BUTTON


#include "element.h"
#include "defines.h"


class button : public element
{
public:
    button():element(){}
    button(int x, int y, int w, int h, sf::String imageFile, sf::String pressedFile, sf::String label="NULL"):
    element(x,y,w,h,imageFile,button_type)
    {
        pressedTexture.loadFromFile(pressedFile);
        initLabel(0,0,label);
    }
    void draw(sf::RenderWindow *window);
    virtual void pressAction();
    virtual void releaseAction();

protected:
    sf::Texture pressedTexture;
};

#endif
