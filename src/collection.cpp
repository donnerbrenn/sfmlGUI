#include "collection.h"

collection::collection()
{
    nextID=0;
    lastTick=runtime.getElapsedTime().asSeconds();
}

collection::~collection()
{
    for(int i=elements.size()-1;i>0;i--)
    {
        if(elements[i]!=nullptr)
            delete(elements[i]);
            elements.erase(elements.begin()+i);
    }
}

bool collection::remove(int idx)
{
    idx=find(idx);
    if(idx!=-1)
    {
        elements.erase(elements.begin()+idx);
        return true;
    }
    return false;
}

int collection::add(element *el)
{
    el->setID(nextID);
    nextID++;
    elements.emplace_back(el);
    return nextID-1;
}

void collection::drawAll(sf::RenderWindow *window)
{
    for(int i=0;i<elements.size();i++)
    {
        elements[i]->draw(window);
    }
}

bool collection::draw(sf::RenderWindow *window, int idx)
{
    idx=find(idx);
    if(idx!=-1)
    {
        elements[idx]->draw(window);
        return true;
    }
    return false;
}

int collection::find(int idx)
{
    for(int i=0;i<elements.size();i++)
    {
        if(elements[i]->getID()==idx)
        {
            return i;
        }
    }
    return (-1);
}

int collection::size()
{
    return elements.size();
}

element *collection::getPtrbyIDX(int idx)
{
    return(elements[idx]);
}

element *collection::getPtrbyID(int id)
{
    int IDX=find(id);
    if(IDX!=-1)
    {
        return getPtrbyIDX(IDX);
    }
    else
    {
        return nullptr;
    }
}

int collection::triggerClickedElement(sf::RenderWindow *window)
{
    sf::Vector2i mousePos=sf::Mouse::getPosition(*window);
    vector2f transformedMousePos(mousePos);
    transformedMousePos=transformMousePos(transformedMousePos,window);
    mousePos.x=transformedMousePos.x;
    mousePos.y=transformedMousePos.y;

    for(int i=0;i<elements.size();i++)
    {
        if(elements[i]->isUnderPos(mousePos))
        {
            elements[i]->pressAction();
            return i;
        }
    }
    return -1;
}

int collection::triggerReleasedElement(sf::RenderWindow *window)
{
    sf::Vector2i mousePos=sf::Mouse::getPosition(*window);
    vector2f transformedMousePos(mousePos);
    transformedMousePos=transformMousePos(transformedMousePos,window);
    mousePos.x=transformedMousePos.x;
    mousePos.y=transformedMousePos.y;

    for(int i=0;i<elements.size();i++)
    {
            elements[i]->releaseAction();
    }
    return -1;
}

void collection::triggerMoveElement(sf::RenderWindow *window, float delta)
{
    for(int i=0;i<elements.size();i++)
    {
        elements[i]->moveAction(delta,window);
    }
}

void collection::triggerEvents(sf::RenderWindow *window, sf::Event event)
{
    currentTick=runtime.getElapsedTime().asSeconds();
    delta=currentTick-lastTick;
    lastTick=currentTick;

    if(event.type==sf::Event::MouseButtonPressed)
    {
        triggerClickedElement(window);
    }
    if(event.type==sf::Event::MouseButtonReleased)
    {
        triggerReleasedElement(window);
    }
    if(event.type==sf::Event::MouseMoved)
    {
        triggerMoveElement(window, delta);
    }
}

vector2f collection::transformMousePos(vector2f mousePos, sf::RenderWindow *window)
{
    vector2f mul;
    vector2f size=window->getSize();
    mul.x=size.x/WIDTH;
    mul.y=size.y/HEIGHT;
    mousePos/=mul;

    return mousePos;    
}
