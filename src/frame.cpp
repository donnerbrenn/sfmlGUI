#include "frame.h"

void frame::draw(sf::RenderWindow *window)
{
    window->draw(border);
    window->draw(back);

    sf::Sprite image;
    image.setTexture(canvas.getTexture());
    image.setPosition(posX,posY);
    window->draw(this->image);
    window->draw(image);
}
