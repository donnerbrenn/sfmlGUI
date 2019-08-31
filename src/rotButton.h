#pragma once
#include "element.h"
#include "vector"

class rotation_button: public element
{
public:
    rotation_button():element(){}
    rotation_button(int x, int y, int w, int h, sf::String imageFile, sf::String pressedFile, std::vector<sf::String> labels, int current=0):
    element(x,y,w,h,imageFile,button_type)
    {
        this->labels=labels;
        pressedTexture.loadFromFile(pressedFile);
        initLabel(0,0,labels[current]);
        this->current=current;
    }
    void draw(sf::RenderWindow *window);
    void pressAction();
    void releaseAction();

protected:
    sf::Texture pressedTexture;
    std::vector<sf::String> labels;
    int current;
};