#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "button.h"
#include "frame.h"
#include "knob.h"
#include "vu.h"
#include "slider.h"
#include "label.h"
#include "oscilloscope.h"
#include "lockbutton.h"
#include "rotButton.h"
#include "element.h"
#include "vector2f.h"
#include "defines.h"

class guiWindow : public sf::RenderWindow
{
public:
    guiWindow(sf::VideoMode mode, const sf::String &title, sf::Uint32 style=sf::Style::Default,const sf::ContextSettings &settings = sf::ContextSettings()):
    sf::RenderWindow(mode,title,style,settings)
    {    
        nextID=0;
        lastTick=runtime.getElapsedTime().asSeconds();
    }    
    ~guiWindow();

    bool remove(int idx);
    int add(element *el);
    void drawAll();
    bool draw(int idx);
    int find(int idx);
    int size();
    element *getPtrbyIDX(int idx);
    element *getPtrbyID(int id);
    void triggerEvents(sf::Event event);


private:
    std::vector<element*> elements;
    int nextID=0;
    float lastTick;
    float currentTick;
    float delta;
    sf::Clock runtime;

    int triggerClickedElement();
    int triggerReleasedElement();
    void triggerMoveElement(float delta);
    vector2f transformMousePos(vector2f mousePos);

};