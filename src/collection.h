#ifndef COLLECTION
#define COLLECTION
#include <vector>
#include <string>
#include "button.h"
#include "frame.h"
#include "knob.h"
#include "vu.h"
#include "slider.h"
#include "element.h"
#include "vector2f.h"
#include "defines.h"

class collection
{
public:
    collection();
    ~collection();
    bool remove(int idx);
    int add(element *el);
    void drawAll(sf::RenderWindow *window);
    bool draw(sf::RenderWindow *window, int idx);
    int find(int idx);
    int size();
    element *getPtrbyIDX(int idx);
    element *getPtrbyID(int id);
    void triggerEvents(sf::RenderWindow *window, sf::Event event);

private:
    std::vector<element*> elements;
    int nextID=0;

    int triggerClickedElement(sf::RenderWindow *window);
    int triggerReleasedElement(sf::RenderWindow *window);
    void triggerMoveElement(sf::RenderWindow *window, float delta);
    vector2f transformMousePos(vector2f mousePos, sf::RenderWindow *window);

    float lastTick;
    float currentTick;
    float delta;
    sf::Clock runtime;
};

#endif