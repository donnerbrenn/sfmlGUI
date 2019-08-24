#include "defines.h"
#include "collection.h"
#include "vector2f.h"
#include <math.h>
#include "synth.h"

int buffersize=44100/(74/2);
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
    setVolume(0,1.0);
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

    int chanDisplayWidth=(WIDTH-20)/VOICES;
    std:: cout << chanDisplayWidth << "\n";

    for(int i=0;i<VOICES;i++)
    {
        id=elements.add(new oscilloscope(10+i*chanDisplayWidth,10,chanDisplayWidth-5,190,synthesizer.getChannelFloatBuffer(i),buffersize,DUALFRAMED,1.0,sf::Color::Black,sf::Color::White));
    }

    // id=elements.add(new oscilloscope(10+0*chanDisplayWidth,10,chanDisplayWidth-5,190,synthesizer.getChannelFloatBuffer(0),buffersize,DUALFRAMED,1.0,sf::Color::Black,sf::Color::White));
    // id=elements.add(new oscilloscope(10+1*chanDisplayWidth,10,chanDisplayWidth-5,190,synthesizer.getChannelFloatBuffer(1),buffersize,DUALFRAMED,1.0,sf::Color::Black,sf::Color::White));
    // id=elements.add(new oscilloscope(10+2*chanDisplayWidth,10,chanDisplayWidth-5,190,synthesizer.getChannelFloatBuffer(2),buffersize,DUALFRAMED,1.0,sf::Color::Black,sf::Color::White));
    // id=elements.add(new oscilloscope(10+3*chanDisplayWidth,10,chanDisplayWidth-5,190,synthesizer.getChannelFloatBuffer(3),buffersize,DUALFRAMED,1.0,sf::Color::Black,sf::Color::White));
    oscID=elements.add(new oscilloscope(10,210,WIDTH-20,700,synthesizer.getFloatBufferPtr(),buffersize,DUALFRAMED,1.0,sf::Color::Black,sf::Color::White));
    elements.add(new label(20,870,"Tetris - Tune"));
    

    id = elements.add(new slider (200,920,"OSC Scale"));
    elements.getPtrbyID(id)->setMin(1.0);
    elements.getPtrbyID(id)->setMax(50.0);
    elements.getPtrbyID(id)->setValue(10.0);
    setOscScale(0,10.0);
    elements.getPtrbyID(id)->setMoveActionPtr(setOscScale);

    id = elements.add(new knob(10,920,"Volume"));
    elements.getPtrbyID(id)->setMin(0);
    elements.getPtrbyID(id)->setMax(1.0);
    elements.getPtrbyID(id)->setValue(synthesizer.getVolume());
    elements.getPtrbyID(id)->setMoveActionPtr(setVolume);

    // id=elements.add(new label(1000,1000,1,true));

    sf::Clock runtime;

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
