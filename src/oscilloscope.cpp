#include "oscilloscope.h"

void oscilloscope::draw(sf::RenderWindow *window)
{
    drawCurve();
    sf::Sprite image;
    image.setTexture(canvas.getTexture());
    image.setPosition(posX,posY);
    window->draw(this->image);
    window->draw(image);
}

void oscilloscope::drawCurve()
{
    canvas.clear(bgColor);
    float step=canvas.getSize().x/float(size-1);
    for(int i=1;i<size;i++)
    {
        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(step*(i-1),data[i-1]*scale*100+canvas.getSize().y*.5),fgColor),
            sf::Vertex(sf::Vector2f(step*i,data[i]*scale*100+canvas.getSize().y*.5),fgColor)
        };
        canvas.draw(line,2,sf::Lines);
    }
    canvas.display();
}

void oscilloscope::setScale(float scale)
{
    this->scale=scale;
}

float oscilloscope::getScale()
{
    return this->scale;
}

void oscilloscope::setBgColor(sf::Color col)
{
    bgColor=col;
}

void oscilloscope::setFgColor(sf::Color col)
{
    fgColor=col;
}

sf::Color oscilloscope::getBgColor()
{
    return bgColor;
}

sf::Color oscilloscope::getFgColor()
{
    return fgColor;
}