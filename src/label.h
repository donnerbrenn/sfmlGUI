#ifndef LABEL
#define LABEL
#include "element.h"


class label : public element
{
public:
    label() : element(){}
    label(int x, int y, sf::String text="EMPTY",bool centered=false):
    element(x, y, 0, 0, "", label_type)
    {
        this->centered=centered;
        font.loadFromFile("bitrmaps/arial.ttf");
        initLabel(x,y,text);
    }

    void draw(sf::RenderWindow *window);
    void initLabel(int x, int y, sf::String text);

protected:
    bool centered;


};


#endif //LABEL