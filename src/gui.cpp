#include "defines.h"
#include "collection.h"
#include "vector2f.h"
#include <math.h>
#include "synth.h"

int buffersize=1024;
vector2f pos;
sf::Texture ball;
sf::Texture ball8;
sf::Texture basketball;
sf::Sprite sprite;
collection elements;
synth synthesizer{1,buffersize,44100};

int oscID=0;
double counter=.0f;

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


void setOscScale(int id, float value)
{
    elements.getPtrbyID(oscID)->setScale(value);
}

void setVolume(int id, float value)
{
    synthesizer.setVolume(value);
}

int main()
{
    synthesizer.play();
    bool running=true;
    sf::Event event;
    sf::RenderWindow window{sf::VideoMode(WIDTH,HEIGHT),"GUI"};
    window.setVerticalSyncEnabled(true);
    sf::RenderTexture *canvas;
    
    int clicked=-1;
    

    sf::String labelTXT;
    int id;
    sf::String buttonImage="bitmaps/button.png";
    sf::String pressedImage="bitmaps/pressed_button.png";


    oscID=elements.add(new oscilloscope(10,10,610+160,450,synthesizer.getFloatBufferPtr(),buffersize,1.0,sf::Color::Blue,sf::Color::White));
    elements.add(new label(20,400,"Tetris - Tune A"));
    

    id = elements.add(new slider (400,530,"OSC Scale"));
    elements.getPtrbyID(id)->setMin(1.0);
    elements.getPtrbyID(id)->setMax(10.0);
    elements.getPtrbyID(id)->setValue(1.0);
    setOscScale(0,1.0);
    elements.getPtrbyID(id)->setMoveActionPtr(setOscScale);

    id = elements.add(new knob(10,480,"Volume"));
    elements.getPtrbyID(id)->setMin(0);
    elements.getPtrbyID(id)->setMax(2.0);
    elements.getPtrbyID(id)->setValue(1.0);
    elements.getPtrbyID(id)->setMoveActionPtr(setVolume);

    while(running)
    {

        window.clear(sf::Color(128,128,128,255));
        elements.drawAll(&window);
        window.display();
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
            {
                synthesizer.stop();
                running=false;                
            }
            elements.triggerEvents(&window,event);        
        }


    }
}
