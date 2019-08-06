#include "label.h"

void label::draw(sf::RenderWindow *window)
{
    window->draw(text);
}

void label::initLabel(int x, int y, sf::String text)
{
    font.loadFromFile("bitmaps/arial.ttf");
    this->text.setFont(font);
    this->text.setString(text);
    this->text.setPosition(x,y);
    this->text.setCharacterSize(20);
    this->text.setOutlineThickness(.5);
    if(centered)
    {
        sf::FloatRect rect=this->text.getGlobalBounds();
        rect.width*=.5;
        rect.height*=.5;
        this->text.setOrigin(rect.width,rect.height);
    }
    else
    {
        this->text.setOrigin(0,0);
    }
    
}

void label::setText(sf::String text)
{
    // this->label=text;
    this->text.setString(text);
}

void label::setInt(int value)
{
    this->text.setString(itoa(value));
    
}

void label::setFloat(float value)
{
    this->text.setString(ftoa(value));
}


void label::init(int x, int y, sf::String text,bool centered)
{
        this->centered=centered;
        font.loadFromFile("bitmaps/arial.ttf");
        initLabel(x,y,text);    
}