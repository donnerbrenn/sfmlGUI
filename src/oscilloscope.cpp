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
    sf::VertexArray curve(sf::LinesStrip,size);
    for(int i=0;i<size;i++)
    {
        curve[i].position=sf::Vector2f(step*i,data[i]*scale*100+canvas.getSize().y*.5);
    }
    canvas.draw(curve);
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