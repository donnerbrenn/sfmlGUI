#include "defines.h"
#include "collection.h"
#include "vector2f.h"


vector2f pos;
sf::Texture ball;
sf::Texture ball8;
sf::Texture basketball;
sf::Sprite sprite;

sf::String cat(sf::String string, int value)
{
    char buffer[100];
    sprintf(buffer,"%d",value);
    string+=" ";
    string+=sf::String(buffer);
    return string;
}


float fX,fY;
int dX=1;
int dY=1;
float rot=-10.1;

void speed(int id, float value)
{
    fX=value;
    fY=value;
}

void rotation(int id, float value)
{
    rot=value;
}

void setBall(int id, float value)
{
    sprite.setTexture(ball);
}

void set8Ball(int id, float value)
{
    sprite.setTexture(ball8);
}

void setBasketball(int id, float value)
{
    sprite.setTexture(basketball);
}


int main()
{
    bool running=true;
    sf::Event event;
    sf::RenderWindow window{sf::VideoMode(WIDTH,HEIGHT),"GUI"};
    window.setVerticalSyncEnabled(true);
    sf::RenderTexture *canvas;
    
    ball.loadFromFile("bitmaps/ball.png");
    ball.setSmooth(true);
    ball8.loadFromFile("bitmaps/8ball.png");
    ball8.setSmooth(true);
    basketball.loadFromFile("bitmaps/basketball.png");
    basketball.setSmooth(true);
    sprite.setTexture(ball);
    sprite.setOrigin(ball.getSize().x/2,ball.getSize().y/2);
    sprite.setPosition(100,100);

    int clicked=-1;
    collection elements;

    sf::String label;
    int id;
    sf::String buttonImage="bitmaps/button.png";
    sf::String pressedImage="bitmaps/pressed_button.png";

    // id=elements.add(new frame(0,0,WIDTH,HEIGHT,"bitmaps/back.png"));
    


    label="Football";
    id=elements.add(new button(20,10,128,32,buttonImage, pressedImage, label));
    elements.getPtrbyIDX(id)->setClickActionPtr(setBall);

    label="8 Ball";
    id=elements.add(new button(20,60,128,32,buttonImage, pressedImage,label));
    elements.getPtrbyIDX(id)->setClickActionPtr(set8Ball);

    label="Basketball";
    id=elements.add(new button(20,110,128,32,buttonImage, pressedImage,label));
    elements.getPtrbyIDX(id)->setClickActionPtr(setBasketball);

    id=elements.add(new knob(180,1005,"Speed"));
    elements.getPtrbyIDX(id)->setValue(6.6);
    elements.getPtrbyIDX(id)->setMax(20.0);
    elements.getPtrbyIDX(id)->setMin(1.0);
    speed(0,6.6);
    elements.getPtrbyIDX(id)->setMoveActionPtr(speed);

    id=elements.add(new knob(290,1005,"Rotation"));
    rotation(0,10.1);
    elements.getPtrbyIDX(id)->setMin(-20);
    elements.getPtrbyIDX(id)->setMax(20);
    elements.getPtrbyIDX(id)->setValue(rot);
    elements.getPtrbyIDX(id)->setMoveActionPtr(rotation);

    id=elements.add(new frame(170,10,1800,19*50+32));
    canvas=elements.getPtrbyID(id)->getCanvas();


    int xVALid=elements.add(new vu(400,1005,256,16,"bitmaps/vu.png","bitmaps/greenVU.png","bitmaps/yellowVU.png","bitmaps/redVU.png",20,"",.0,1800));
    
    int yVALid=elements.add(new vu(400,1025,256,16,"bitmaps/vu.png","bitmaps/greenVU.png","bitmaps/yellowVU.png","bitmaps/redVU.png",20,"",.0,19*50+32));

    while(running)
    {
        window.clear(sf::Color(128,128,128,255));
        elements.drawAll(&window);
        window.display();
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
            {
                running=false;                
            }
            elements.triggerEvents(&window,event);        
        }
        //RGBA
        canvas->clear(sf::Color::Blue);
        pos=sprite.getPosition();
        pos+=vector2f(fX*dX,fY*dY);


        if(pos.x<ball.getSize().x/2 || pos.x>canvas->getSize().x-ball.getSize().x/2)
        {
            dX*=-1;
        }
        
        if(pos.y<ball.getSize().y/2 || pos.y>canvas->getSize().y-ball.getSize().y/2)
        {
            dY*=-1;
        }

        elements.getPtrbyID(xVALid)->setValue(pos.x);
        elements.getPtrbyID(yVALid)->setValue(pos.y);

        sprite.setPosition(pos);
        sprite.setRotation(sprite.getRotation()+rot);

        canvas->draw(sprite);
        canvas->display();
    }
}
