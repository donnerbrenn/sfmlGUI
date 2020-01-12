#include "defines.h"
#include "vector2f.h"
#include <math.h>
#include "synth.h"
// #include "iostream"
#include "vector"
#include SONG
#include "guiWindow.h"


int buffersize=44100/(75/4);
vector2f pos;
guiWindow elements(sf::VideoMode(WIDTH,HEIGHT),"sfmlGUI",sf::Color(128,128,128));
synth synthesizer{1,buffersize,96000};
bool isPlaying=true;

int oscID=0;
double counter=.0f;

noteLabel *noteLabels[5][20];

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

enum function{none=0,a,d,s,r,delay,strength,cutoff,resonance, volume, svolume, muting, smuting, changeform, changesform, flt, freqmod};

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

 std::vector<sf::String> oscNames;
 std::vector<sf::String> fltNames;

void changeChannelSetting(int id,float value)
{
    int ivalue=int(value);
    for(int i=0;i<knobLayout.size();i++)
    {
        if(knobLayout[i].id==id)
        {
            switch (knobLayout[i].value)
            {
            case a:
                synthesizer.setEnvelopeA(knobLayout[i].voice,value);
                return;
                break;
            case d:
                synthesizer.setEnvelopeD(knobLayout[i].voice,value);
                return;
                break;
            case s:
                synthesizer.setEnvelopeS(knobLayout[i].voice,value);
                return;
                break;
                case r:
                synthesizer.setEnvelopeR(knobLayout[i].voice,value);
                return;
                break;
            case cutoff:
                synthesizer.setFilterCutoff(knobLayout[i].voice,value*.99);
                return;
                break;
            case resonance:
                synthesizer.setFilterResonance(knobLayout[i].voice,value*.99);
                return;
                break;
            case strength:
                synthesizer.setEffectStrength(knobLayout[i].voice,value);
                return;
                break;
            case delay:
                synthesizer.setEffectDelay(knobLayout[i].voice,value);
                return;
                break;
            case volume:
                synthesizer.setInstrumentVolume(knobLayout[i].voice,value);
                return;
                break;
            case svolume:
                synthesizer.setInstrumentSubVolume(knobLayout[i].voice,value);
                return;
                break;
            case muting:
                synthesizer.switchInstrumentMuted(knobLayout[i].voice);
                return;
                break;
            case smuting:
                synthesizer.switchInstrumentSMuted(knobLayout[i].voice);
                return;
                break;
            case freqmod:
                synthesizer.switchInstrumentFreqModulate(knobLayout[i].voice);
                return;
                break;

            default:
                break;
            }
        }
    }
}

void changeWaveform(int id, float fvalue)
{
    int value=fvalue;
    for(int i=0;i<knobLayout.size();i++)
    {
        if(knobLayout[i].id==id)
        {
            switch (knobLayout[i].value)
            {
                case changeform:
                    synthesizer.setWaveform(knobLayout[i].voice,osc(value));
                    return;
                    break;
                case changesform:
                    synthesizer.setSWaveform(knobLayout[i].voice,osc(value));
                    return;
                    break;
                case flt:
                    synthesizer.setFilter(knobLayout[i].voice,mode(value));
                    return;
            }
        }
    }
}

void createGUI(double chanDisplayWidth, sf::String buttonImage, sf::String pressedImage)
{
    int xSpacing=90;
    int ySpacing=150;
    int yOffset=175;
    int knobXOffset=20;
    int id;
    element *currentKnob;


    
    for(int i=0;i<VOICES;i++)
    {
        
        // sf::Color color;
        for(int x=0;x<5;x++)
        {
            for(int y=0;y<20;y++)
            {
                // color=(y==0)?sf::Color::Green:sf::Color::White;
                id=elements.add(new noteLabel(80+x*chanDisplayWidth,700+y*30,"",(y==0)?sf::Color::Green:sf::Color::White));
                noteLabels[x][y]=(noteLabel*)elements.getPtrbyID(id);
            }
        }

        
        id=elements.add(new oscilloscope(10+i*chanDisplayWidth,10,chanDisplayWidth-5,120,synthesizer.getChannelFloatBuffer(i),buffersize,DUALFRAMED,1.0,sf::Color::Black,sf::Color::White));
        id=elements.add(new label(10+i*chanDisplayWidth+5,10,descriptions[i].name));

        id=elements.add(new frame(10+i*chanDisplayWidth,yOffset-38,chanDisplayWidth-5,142,"",sf::Color(100,100,100)));
        id=elements.add(new frame(10+i*chanDisplayWidth,yOffset-38+ySpacing,chanDisplayWidth-5,142+40,"",sf::Color(100,100,100)));
        id=elements.add(new frame(10+i*chanDisplayWidth,yOffset-38+ySpacing*2+42,chanDisplayWidth-5,110,"",sf::Color(100,100,100)));
 
        id=elements.add(new label(10+i*chanDisplayWidth+2*xSpacing,yOffset-30,"Envelope",true));
        
        id=elements.add(new knob (knobXOffset+i*chanDisplayWidth,yOffset,"A"));
        knobLayout.emplace_back(knobLink{id,i,a});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setMax(1.0);
        currentKnob->setValue(descriptions[i].a);
        currentKnob->setMoveActionPtr(changeChannelSetting);

        id=elements.add(new knob (knobXOffset+i*chanDisplayWidth+xSpacing,yOffset,"D"));
        knobLayout.emplace_back(knobLink{id,i,d});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setMax(4.0);
        currentKnob->setValue(descriptions[i].d);
        currentKnob->setMoveActionPtr(changeChannelSetting);

        id=elements.add(new knob (knobXOffset+i*chanDisplayWidth+xSpacing*2,yOffset,"S"));
        knobLayout.emplace_back(knobLink{id,i,s});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setMax(1.0);
        currentKnob->setValue(descriptions[i].s);
        currentKnob->setMoveActionPtr(changeChannelSetting);

        id=elements.add(new knob (knobXOffset+i*chanDisplayWidth+xSpacing*3,yOffset,"R"));
        knobLayout.emplace_back(knobLink{id,i,r});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setMax(1.0);
        currentKnob->setValue(descriptions[i].r);
        currentKnob->setMoveActionPtr(changeChannelSetting);

        id=elements.add(new label(10+i*chanDisplayWidth+xSpacing,yOffset+ySpacing-30,"Echo",true));

        id=elements.add(new knob (knobXOffset+i*chanDisplayWidth,yOffset+ySpacing,"Delay"));
        knobLayout.emplace_back(knobLink{id,i,delay});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setMax(1.0);
        currentKnob->setValue(descriptions[i].delay);
        currentKnob->setMoveActionPtr(changeChannelSetting);

        id=elements.add(new knob (knobXOffset+i*chanDisplayWidth+xSpacing,yOffset+ySpacing,"Strength"));
        knobLayout.emplace_back(knobLink{id,i,strength});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setMax(1.0);
        currentKnob->setValue(descriptions[i].strength);
        currentKnob->setMoveActionPtr(changeChannelSetting);


        id=elements.add(new label(10+i*chanDisplayWidth+xSpacing*3,yOffset+ySpacing-30,"Filter",true));

        id=elements.add(new knob (knobXOffset+i*chanDisplayWidth+xSpacing*2,yOffset+ySpacing,"Cutoff"));
        knobLayout.emplace_back(knobLink{id,i,cutoff});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setMax(1.0);
        currentKnob->setValue(descriptions[i].cutoff);
        currentKnob->setMoveActionPtr(changeChannelSetting);

        id=elements.add(new knob (knobXOffset+i*chanDisplayWidth+xSpacing*3,yOffset+ySpacing,"Resonance"));
        knobLayout.emplace_back(knobLink{id,i,resonance});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setMax(1.0);
        currentKnob->setValue(descriptions[i].resonance);
        currentKnob->setMoveActionPtr(changeChannelSetting);

        id=elements.add(new rotation_button(10+i*chanDisplayWidth+xSpacing*2+28,yOffset+ySpacing*1.725,128,32,buttonImage,pressedImage,fltNames,descriptions[i].useFilter));
        knobLayout.emplace_back(knobLink{id,i,flt});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setClickActionPtr(changeWaveform);

        id=elements.add(new lockbutton(10+i*chanDisplayWidth+xSpacing*2+28,yOffset+ySpacing*2+30,128,32,buttonImage,pressedImage,"Freq Modulate",descriptions[i].freqModulate));
        knobLayout.emplace_back(knobLink{id,i,freqmod});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setClickActionPtr(changeChannelSetting);
        currentKnob->setReleaseActionPtr(changeChannelSetting);
        currentKnob->setScale(2);
        
        id=elements.add(new knob (knobXOffset+i*chanDisplayWidth,yOffset+ySpacing*2+10,"Volume"));
        knobLayout.emplace_back(knobLink{id,i,volume});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setMax(1.0);
        currentKnob->setValue(descriptions[i].volume);
        currentKnob->setMoveActionPtr(changeChannelSetting);

        id=elements.add(new knob (knobXOffset+i*chanDisplayWidth+xSpacing,yOffset+ySpacing*2+10,"Sub-Vol."));
        knobLayout.emplace_back(knobLink{id,i,svolume});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setMax(1.0);
        currentKnob->setValue(descriptions[i].sub_volume);
        currentKnob->setMoveActionPtr(changeChannelSetting);

        id=elements.add(new lockbutton(10+i*chanDisplayWidth+48,yOffset+3.1*ySpacing,128,32,buttonImage,pressedImage,"Mute"));
        knobLayout.emplace_back(knobLink{id,i,muting});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setClickActionPtr(changeChannelSetting);
        currentKnob->setReleaseActionPtr(changeChannelSetting);

        id=elements.add(new lockbutton(10+i*chanDisplayWidth+130+48,yOffset+3.1*ySpacing,128,32,buttonImage,pressedImage,"Sub Mute"));
        knobLayout.emplace_back(knobLink{id,i,smuting});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setClickActionPtr(changeChannelSetting);
        currentKnob->setReleaseActionPtr(changeChannelSetting);

        id=elements.add(new rotation_button(10+i*chanDisplayWidth+48,yOffset+2.8*ySpacing,128,32,buttonImage,pressedImage,oscNames,descriptions[i].waveform));
        knobLayout.emplace_back(knobLink{id,i,changeform});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setClickActionPtr(changeWaveform);

        id=elements.add(new rotation_button(10+i*chanDisplayWidth+130+48,yOffset+2.8*ySpacing,128,32,buttonImage,pressedImage,oscNames,descriptions[i].sub_waveform));
        knobLayout.emplace_back(knobLink{id,i,changesform});
        currentKnob=elements.getPtrbyID(id);
        currentKnob->setClickActionPtr(changeWaveform);
    }
    // id = elements.add(new slider(58,690,"Volume"));
    // elements.getPtrbyID(id)->setMin(0);
    // elements.getPtrbyID(id)->setMax(1.0);
    // elements.getPtrbyID(id)->setValue(synthesizer.getVolume());
    // elements.getPtrbyID(id)->setMoveActionPtr(setVolume);

    std::cout << elements.getElementCount() << "\n";
}

int main()
{
    oscNames.emplace_back("Mute");
    oscNames.emplace_back("Sine");
    oscNames.emplace_back("Triangle");
    oscNames.emplace_back("Square");
    oscNames.emplace_back("Saw");
    oscNames.emplace_back("RSaw");
    oscNames.emplace_back("Noise");

    fltNames.emplace_back("None");
    fltNames.emplace_back("Highpass");
    fltNames.emplace_back("Lowpass");
    fltNames.emplace_back("Bandpass");

    setVolume(0,1.0);
    synthesizer.play();
    bool running=true;
    sf::Event event;
    elements.setVerticalSyncEnabled(true);
    // elements.setFramerateLimit(5);
    sf::RenderTexture *canvas;
    
    int clicked=-1;
    
    sf::String labelTXT;
    int id;
    sf::String buttonImage="bitmaps/button.png";
    sf::String pressedImage="bitmaps/pressed_button.png";

    int chanDisplayWidth=(WIDTH-20)/VOICES;
    createGUI(chanDisplayWidth,buttonImage,pressedImage);


    while(running)
    {
        elements.redraw();
        while(elements.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
            {
                synthesizer.stop();
                running=false;                
            }
            elements.triggerEvents(event);        
        }

        for(int x=0;x<5;x++)
        {
            for(int y=0;y<20;y++)
            {
                int note=synthesizer.getCurrentNote(x,y);
                noteLabels[x][y]->setNote(note);
            }
        }
    }

}
