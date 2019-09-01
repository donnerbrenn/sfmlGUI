#include "guiWindow.h"

guiWindow::~guiWindow()
{
    for(int i=elements.size()-1;i>0;i--)
    {
        if(elements[i]!=nullptr)
            delete(elements[i]);
            elements.erase(elements.begin()+i);
    }
}

bool guiWindow::remove(int idx)
{
    idx=find(idx);
    if(idx!=-1)
    {
        elements.erase(elements.begin()+idx);
        return true;
    }
    return false;
}

int guiWindow::add(element *el)
{
    el->setID(nextID);
    nextID++;
    elements.emplace_back(el);
    return nextID-1;
}
void guiWindow::redraw()
{
    this->clear(bgColor);
    for(int i=0;i<elements.size();i++)
    {
        elements[i]->draw(this);
    }
    this->display();
}

bool guiWindow::draw(int idx)
{
    idx=find(idx);
    if(idx!=-1)
    {
        elements[idx]->draw(this);
        return true;
    }
    return false;
}

int guiWindow::find(int idx)
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

int guiWindow::size()
{
    return elements.size();
}

element *guiWindow::getPtrbyIDX(int idx)
{
    return(elements[idx]);
}

element *guiWindow::getPtrbyID(int id)
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

void guiWindow::triggerEvents(sf::Event event)
{
    currentTick=runtime.getElapsedTime().asSeconds();
    delta=currentTick-lastTick;
    lastTick=currentTick;

    if(event.type==sf::Event::MouseButtonPressed)
    {
        triggerClickedElement();
    }
    if(event.type==sf::Event::MouseButtonReleased)
    {
        triggerReleasedElement();
    }
    if(event.type==sf::Event::MouseMoved)
    {
        triggerMoveElement(delta);
    }
}

int guiWindow::triggerClickedElement()
{
    sf::Vector2i mousePos=sf::Mouse::getPosition(*this);
    vector2f transformedMousePos(mousePos);
    transformedMousePos=transformMousePos(transformedMousePos);
    mousePos.x=transformedMousePos.x;
    mousePos.y=transformedMousePos.y;

    for(int i=0;i<elements.size();i++)
    {
        if(elements[i]->isUnderPos(mousePos)&&elements[i]->getType()!=frame_type)
        {
            elements[i]->pressAction();
            return i;
        }
    }
    return -1;
}

int guiWindow::triggerReleasedElement()
{
    sf::Vector2i mousePos=sf::Mouse::getPosition(*this);
    vector2f transformedMousePos(mousePos);
    transformedMousePos=transformMousePos(transformedMousePos);
    mousePos.x=transformedMousePos.x;
    mousePos.y=transformedMousePos.y;

    for(int i=0;i<elements.size();i++)
    {
            elements[i]->releaseAction();
    }
    return -1;
}

void guiWindow::triggerMoveElement(float delta)
{
    for(int i=0;i<elements.size();i++)
    {
        elements[i]->moveAction(delta,this);
    }
}

vector2f guiWindow::transformMousePos(vector2f mousePos)
{    
    vector2f mul;
    vector2f size=this->getSize();
    mul.x=size.x/WIDTH;
    mul.y=size.y/HEIGHT;
    mousePos/=mul;
    return mousePos;
}


