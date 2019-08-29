#include "defines.h"
#include "collection.h"
#include "vector2f.h"
#include <math.h>
#include "synth.h"
#include "iostream"
#include "vector"
#include SONG


int buffersize=44100/(74/2);
vector2f pos;
sf::Texture ball;
sf::Texture ball8;
sf::Texture basketball;
sf::Sprite sprite;
collection elements;
synth synthesizer{1,buffersize,44100};
bool isPlaying=true;

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

enum function{none=0,a,d,s,r,delay,strength,cutoff,resonance};

struct knobLink
{
    int id;
    int voice;
    int value;
};
std::vector<knobLink> knobLayout;

void setVolume(int id, float value)
{
    synthesizer.setVolume(value);
}

void stop(int id, float value)
{
        synthesizer.stop();
        isPlaying=false;
}

void play(int id, float value)
{
        synthesizer.play();
        isPlaying=true;
}

void changeChannelSetting(int id,float value)
{
    double *target;
    for(int i=0;i<knobLayout.size();i++)
    {
        if(knobLayout[i].id==id)
        {
            switch (knobLayout[i].value)
            {
            case a:
                //target=&descriptions[knobLayout[i].voice].a;
                break;
            
            default:
                break;
            }
        }
    }
    //*target=value;
}


int main()
{
    std::cout << "Buffersize: " << buffersize << "\n";
    setVolume(0,1.0);
    synthesizer.play();
    bool running=true;
    sf::Event event;
    sf::RenderWindow window{sf::VideoMode(WIDTH,HEIGHT),"GUI"};
    window.setVerticalSyncEnabled(true);
    // window.setFramerateLimit(2);
    sf::RenderTexture *canvas;
    
    int clicked=-1;
    
    sf::String labelTXT;
    int id;
    sf::String buttonImage="bitmaps/button.png";
    sf::String pressedImage="bitmaps/pressed_button.png";

    int chanDisplayWidth=(WIDTH-20)/VOICES;
    element *currentKnob;

    for(int i=0;i<VOICES;i++)
    {
        id=elements.add(new oscilloscope(10+i*chanDisplayWidth,10,chanDisplayWidth-5,240,synthesizer.getChannelFloatBuffer(i),buffersize,DUALFRAMED,1.0,sf::Color::Black,sf::Color::White));
        id=elements.add(new knob (10+i*chanDisplayWidth,260,"A"));
        knobLayout.emplace_back(knobLink{id,i,a});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setMax(4.0);
        currentKnob->setValue(descriptions[i].a);
        currentKnob->setMoveActionPtr(changeChannelSetting);

        id=elements.add(new knob (10+i*chanDisplayWidth,380,"D"));
        knobLayout.emplace_back(knobLink{id,i,d});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setMax(4.0);
        currentKnob->setValue(descriptions[i].d);

        id=elements.add(new knob (10+i*chanDisplayWidth,500,"S"));
        knobLayout.emplace_back(knobLink{id,i,s});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setMax(4.0);
        currentKnob->setValue(descriptions[i].s);

        id=elements.add(new knob (10+i*chanDisplayWidth,620,"R"));
        knobLayout.emplace_back(knobLink{id,i,r});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setMax(4.0);
        currentKnob->setValue(descriptions[i].r);

        id=elements.add(new knob (10+i*chanDisplayWidth+100,260,"Delay"));
        knobLayout.emplace_back(knobLink{id,i,delay});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setMax(4.0);
        currentKnob->setValue(descriptions[i].delay);

        id=elements.add(new knob (10+i*chanDisplayWidth+100,380,"Strength"));
        knobLayout.emplace_back(knobLink{id,i,strength});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setMax(4.0);
        currentKnob->setValue(descriptions[i].strength);

        id=elements.add(new knob (10+i*chanDisplayWidth+100,500,"Cutoff"));
        knobLayout.emplace_back(knobLink{id,i,cutoff});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setMax(4.0);
        currentKnob->setValue(descriptions[i].cutoff);

        id=elements.add(new knob (10+i*chanDisplayWidth+100,620,"Resonance"));
        knobLayout.emplace_back(knobLink{id,i,resonance});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setMax(4.0);
        currentKnob->setValue(descriptions[i].resonance);
    }

    id = elements.add(new slider(10,810,"Volume"));
    elements.getPtrbyID(id)->setMin(0);
    elements.getPtrbyID(id)->setMax(1.0);
    elements.getPtrbyID(id)->setValue(synthesizer.getVolume());
    elements.getPtrbyID(id)->setMoveActionPtr(setVolume);

    id=elements.add(new lockbutton(1600,970,128,32,buttonImage,pressedImage,"Pause"));
    elements.getPtrbyID(id)->setClickActionPtr(stop);
    elements.getPtrbyID(id)->setReleaseActionPtr(play);

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
