#include "noteLabel.h"

void noteLabel::setNote(int note)
{
    
    std::stringstream stream;
    if(note==0)
    {
        stream << "-----";
    }
    else
    {
        stream << noteNames[note%12];
        stream << "-";
        stream << note/12;
    }
    
    setText(stream.str());
}
