#include "rotButton.h"

void rotation_button::draw(sf::RenderWindow *window)
{
    drawSprite(window);
    drawLabel(window);
}

void rotation_button::pressAction()
{
    this->current++;
    this->current%=labels.size();
    initLabel(0,0,labels[current]);
    image.setTexture(pressedTexture);
    performAction(clickActionPtr,current);
}

void rotation_button::releaseAction()
{

    image.setTexture(texture);
    performAction(releaseActionPtr,0);
}