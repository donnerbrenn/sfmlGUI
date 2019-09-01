#include "frame.h"

void frame::draw(sf::RenderWindow *window)
{
    sf::RectangleShape border;
    sf::RectangleShape back;
    border.setSize(sf::Vector2f(width,height));
    border.setFillColor(fgColor);
    border.setPosition(posX,posY);
    window->draw(border);

    back.setSize(sf::Vector2f(width-4,height-4));
    back.setFillColor(bgColor);
    back.setPosition(posX+2,posY+2);
    window->draw(back);



    sf::Sprite image;
    image.setTexture(canvas.getTexture());
    image.setPosition(posX,posY);
    window->draw(this->image);
    window->draw(image);
}
