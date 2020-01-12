#include "knob.h"

void knob::draw(sf::RenderWindow *window)
{
    window->draw(image);
    window->draw(overlay);
    window->draw(display);
    drawLabel(window);
}

void knob::setValue(float value)
{
    if (value<minimum)value=minimum;
    if (value>maximum)value=maximum;
    this->value=value;
    update();
}

float knob::getValue()
{
    return value;
}

void knob::update()
{
    float divider=320.0/getRange();
    float newRotation=(value-minimum)*divider+20;
    overlay.setRotation(newRotation);
    display.setString(ftoa(value));
    initDisplay(0,68);
}

void knob::pressAction()
{
    isPressed=true;
    lastPos=sf::Mouse::getPosition();
    performAction(clickActionPtr);
    update();
}

void knob::releaseAction()
{
    isPressed=false;
    performAction(releaseActionPtr);
}

void knob::moveAction(float delta, sf::RenderWindow *window)
{
    sf::Vector2i movement;
    if(isPressed)
    {
        sf::Vector2i newPos=sf::Mouse::getPosition();
        movement=newPos-lastPos;
        lastPos=newPos;
        setValue(getValue()+movement.x*delta*.025*getRange());
        performAction(moveActionPtr,value);
    }
}

void knob::setMin(float value)
{
    minimum=value;
    setValue(this->value);
    update();
}

void knob::setMax(float value)
{
    maximum=value;
    setValue(this->value);
    update();
}

float knob::getMin()
{
    return minimum;
}

float knob::getMax()
{
    return maximum;
}

float knob::getRange()
{
    return maximum-minimum;
}

void knob::initDisplay(int x, int y, int charSize)
{
    display.setFont(font);
    display.setOutlineThickness(.5);
    display.setPosition(posX+width/2+x,posY+height/3+y);
    display.setCharacterSize(charSize);
    sf::FloatRect textRect = display.getLocalBounds();
    display.setOrigin(textRect.width/2,textRect.height/2);
}