#include "vu.h"


void vu::draw(sf::RenderWindow *window)
{
    drawSprite(window);
    for(int i=0;i<members.size();i++)
    {
        window->draw(members[i]);
    }
}

float vu::getRange()
{
    return maximum-minimum;
}

void vu::update()
{
    float step=getRange()/members.size();
    float current=minimum;
    for(int i=0;i<members.size();i++)        
    {
        if(value>current)        
        {
            members[i].setColor(sf::Color::White);
        }
        else
        {
            members[i].setColor(sf::Color(64,64,64,255));
        }
        current+=step;
    }
}

void vu::setMinimum(float value)
{
    minimum=value;
}

void vu::setMamimum(float value)
{
    maximum=value;    
}

void vu::setValue(float value)
{
    if(value<minimum)
        value=minimum;
    if(value>maximum)
        value=maximum;
    this->value=value;
    update();
}