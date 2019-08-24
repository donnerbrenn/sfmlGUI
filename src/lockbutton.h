#pragma once
#include "button.h"

class lockbutton: public button
{
public:
    lockbutton():button(){}
    lockbutton(int x, int y, int w, int h, sf::String imageFile, sf::String pressedFile, sf::String label="NULL"):
    button(x, y, w, h, imageFile, pressedFile, label)
    {

    }

    void pressAction();
    void releaseAction();
    bool isLocked();

protected:
    bool locked=false;


};
