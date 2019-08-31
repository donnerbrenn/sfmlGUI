#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "defines.h"

class element
{
public:
    element();
    element(int x, int y, int w, int h, std::string imageFileName, int type=element_type);
    ~element();
    int getType();
    void drawSprite(sf::RenderWindow *window);
    void drawLabel(sf::RenderWindow *window);
    bool isUnderMouse(sf::RenderWindow *window);
    bool isUnderPos(sf::Vector2i mousePos);
    sf::RenderTexture *getCanvas();
    virtual void setValue(float value){}
    virtual void update(){}
    virtual void pressAction();
    virtual void releaseAction();
    virtual void moveAction(float delta, sf::RenderWindow *window);
    virtual void draw(sf::RenderWindow *window){}
    virtual void setMax(float value){}
    virtual void setMin(float value){}
    virtual void setScale(float value){}

    void setClickActionPtr(void (*ptr)(int id, float value)=nullptr);
    void setReleaseActionPtr(void (*ptr)(int id, float value)=nullptr);
    void setMoveActionPtr(void (*ptr)(int id, float value)=nullptr);

    void setID(int id);
    int getID();


protected:
    std::string imageFileName="white.png";
    std::string overlayFileName="white.png";
    sf::Sprite image;
    sf::Texture texture;
    sf::Sprite overlay;
    sf::Texture overlay_texture;
    sf::Font font;
    sf::Text text;
    sf::String label="Undefined";
    sf::RenderTexture canvas;
    int posX;
    int posY;
    int width;
    int height;
    int type=element_type;

    void initCanvas(int w, int h);
    void initLabel(int x, int y, sf::String label);
    void initImage(int x, int y);
    void initOverlay(int x, int y);  
    void performAction(void(*ptr)(int id, float value), float value=.0f);

    void (*clickActionPtr)(int id, float value)=nullptr;  
    void (*releaseActionPtr)(int id, float value)=nullptr;  
    void (*moveActionPtr)(int id, float value)=nullptr;

    sf::String ftoa(float i);
    sf::String itoa(int i);

    int id=0;

private:
};
