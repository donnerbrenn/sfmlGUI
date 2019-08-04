#ifndef SLIDER
#define SLIDER
#include "element.h"


class slider : public element
{
public:
    slider():element(){}
    slider(int x, int y, sf::String label="Slider", int w=256, int h=32):element(x,y,w,h,"bitmaps/slider.png",slider_type)
    {
        setValue(value);
        knob_texture.loadFromFile("bitmaps/slider_knob.png");
        knob_sprite.setTexture(knob_texture);
        initImage(x,y);
    }
    
    void draw(sf::RenderWindow *window);
    float getRange();
    void setMin(float value);
    void setMax(float value);
    void setValue(float value);
    float getValue();
    void update();
    void pressAction();
    void releaseAction();
    void moveAction(float delta);
    float getMin();
    float getMax();

protected:
    sf::Texture slider_texture;
    sf::Sprite slider_sprite;

    sf::Texture knob_texture;
    sf::Sprite knob_sprite;

    float value=0;
    float minimum=0;
    float maximum=100;
    bool isPressed=false;
    sf::Vector2i lastPos;
};

#endif