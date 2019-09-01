#include "noteDisplay.h"
#include "decode.h"

void noteDisplay::draw(sf::RenderWindow *window)
{
    
    for(int i=0;i<labels.size();i++)
    {
        // label tempLabel(x,y+20*i,labels[i],false);
        label tempLabel(x,y+20*i,"test",false);
        tempLabel.draw(window);
        
    }
}

sf::String noteDisplay::valueToNote(int value)
{
    sf::String note=noteNames[value%12];
    note+="-";
    note+=itoa(value/12);
    return note;
}

void noteDisplay::update(double time)
{
    int prevNotes=rows/2-1;
    int nextNotes=rows/2;

    int pos = time*SPEED*5;
    char note;

    // for(int i=prevNotes;i>=0;i--)
    // {
    //     note = cpatterns[channel][((pos-i-1)/PATTERNLENGTH)%LENGTH][(pos-i-1)%PATTERNLENGTH];
    //     labels[prevNotes-i]=valueToNote(note);
    // }
    note = cpatterns[channel][(pos/PATTERNLENGTH)%LENGTH][pos%PATTERNLENGTH];
    labels[prevNotes]=valueToNote(note);
}