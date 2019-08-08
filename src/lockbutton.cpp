#include "lockbutton.h"


void lockbutton::pressAction()
{
    if(isLocked())
    {
        locked=false;
        image.setTexture(texture);
        performAction(releaseActionPtr,0);
    }
    else
    {
        locked=true;
        image.setTexture(pressedTexture);
        performAction(clickActionPtr,0);        
    }
}

void lockbutton::releaseAction()
{

}

bool lockbutton::isLocked()
{
    return locked;
}