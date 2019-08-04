#include "slider.h"

void slider::draw(sf::RenderWindow *window)
{
    window->draw(image);
    window->draw(knob_sprite);
}


float slider::getRange()
{
    return maximum-minimum;
}

void slider::setMin(float value)
{
    this->minimum=value;
}

void slider::setMax(float value)
{
    this->maximum=value;
}

void slider::setValue(float value)
{
    if (value<minimum)value=minimum;
    if (value>maximum)value=maximum;
    this->value=value;
    update();
}

void slider::update()
{
    float divider=(texture.getSize().x-36)/getRange();
    float newX=(value-minimum)*divider+4;
    knob_sprite.setPosition(newX+posX,posY+4);
    // display.setString(ftoa(value));
    // initDisplay(0,68);
}

void slider::pressAction()
{
    isPressed=true;
    lastPos=sf::Mouse::getPosition();
    performAction(clickActionPtr);
    update();
}

void slider::releaseAction()
{
    isPressed=false;
    performAction(releaseActionPtr);
}

void slider::moveAction(float delta)
{
    sf::Vector2i movement;
    if(isPressed)
    {
        sf::Vector2i newPos=sf::Mouse::getPosition();
        movement=newPos-lastPos;
        lastPos=newPos;
        setValue(getValue()+movement.x*(delta*10));
        performAction(moveActionPtr,value);
    }
}

float slider::getMin()
{
    return minimum;
}


float slider::getMax()
{
    return maximum;
}

float slider::getValue()
{
    return value;
}
