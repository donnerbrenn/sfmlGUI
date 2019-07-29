#include "button.h"

void button::draw(sf::RenderWindow *window)
{
    drawSprite(window);
    drawLabel(window);
}

void button::pressAction()
{
    image.setTexture(pressedTexture);
    performAction(clickActionPtr,0);
}

void button::releaseAction()
{
    image.setTexture(texture);
    performAction(releaseActionPtr,0);
}
