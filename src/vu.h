#include "element.h"
#include <vector>
// #include <iostream>

class vu : public element
{
public:
vu():element(){}
vu(int x, int y, int w, int h, sf::String imageFile, sf::String greenfile, sf::String yellowFile, sf::String redFile, int memberCnt, sf::String label="NULL", float min=0,float max=100):
element(x,y,w,h,imageFile,vu_type)
{
    minimum=min;
    maximum=max;
    texture.loadFromFile(imageFile);
    image.setTexture(texture);
    image.setPosition(x,y);
    green.loadFromFile(greenfile);
    yellow.loadFromFile(yellowFile);
    red.loadFromFile(redFile);
    int div=memberCnt/3;
    sf::Sprite protoType;
    protoType.setColor(sf::Color(64,64,64,255));
    protoType.setTexture(green);
    for(int i=0;i<memberCnt;i++)
    {
        protoType.setPosition(12*i+10+x,3+y);
        members.emplace_back(protoType);
    }
    for(int i=1;i<=div;i++)
    {
        members[members.size()-i].setTexture(red);
    }
    for(int i=1;i<=div;i++)
    {
        members[members.size()-i-div].setTexture(yellow);
    }
}
float getRange();
void update();
void setValue(float value);
void setMinimum(float value);
void setMamimum(float value);

void draw(sf::RenderWindow *window);

protected:
    float value;
    float minimum;
    float maximum;
    sf::Texture red;
    sf::Texture green;
    sf::Texture yellow;
    std::vector<sf::Sprite> members;
};