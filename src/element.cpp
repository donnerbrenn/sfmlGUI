#include "element.h"

element::element()
{
}

element::element(int x, int y, int w, int h, std::string imageFileName, int type)
{
    this->type=type;
    this->imageFileName=imageFileName;
    this->label=label;

    posX=x;
    posY=y;
    width=w;
    height=h; 
    initImage(x,y);
}

void element::performAction(void(*ptr)(int id, float value), float value)
{
    if(ptr!=nullptr)
        ptr(id,value);
}

void element::setClickActionPtr(void (*ptr)(int id, float value))
{
    clickActionPtr=ptr;
}

void element::setReleaseActionPtr(void (*ptr)(int id, float value))
{
    releaseActionPtr=ptr;
}

void element::setMoveActionPtr(void (*ptr)(int id, float value))
{
    moveActionPtr=ptr;
}

element::~element()
{    
}

int element::getType()
{
    return type;
}

void element::initCanvas(int w, int h)
{
    canvas.create(w,h);
    canvas.clear();
    canvas.display();
    image.setTexture(canvas.getTexture());
    image.setPosition(posX,posY);
}

void element::pressAction()
{
    performAction(clickActionPtr);
}

void element::releaseAction()
{
    performAction(releaseActionPtr);
}
void element::moveAction(float delta)
{
    performAction(moveActionPtr);
}

void element::initLabel(int x, int y, sf::String label)
{
    this->label=label;
    font.loadFromFile("bitmaps/arial.ttf");
    text.setFont(font);
    text.setOutlineThickness(.5);
    text.setPosition(posX+width/2+x,posY+height/3+y);
    text.setCharacterSize(20);
    text.setString(label);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.width/2,textRect.height/2);
}

void element::initImage(int x, int y)
{
    texture.loadFromFile(imageFileName);
    texture.setSmooth(true);
    image.setTexture(texture);
    float scaleX=width/texture.getSize().x;
    float scaleY=height/texture.getSize().y;
    image.setScale(scaleX,scaleY);
    image.setPosition(x,y);
}

void element::initOverlay(int x, int y)
{
    overlay_texture.loadFromFile(overlayFileName);
    overlay_texture.setSmooth(true);
    overlay.setTexture(overlay_texture);
    sf::FloatRect boundaries=image.getGlobalBounds();
    boundaries.width/=2;
    boundaries.height/=2;
    overlay.setOrigin(boundaries.width,boundaries.height);
    overlay.setPosition(x+boundaries.width,y+boundaries.height);
}

sf::RenderTexture* element::getCanvas()
{
    return (&this->canvas);    
}

bool element::isUnderPos(sf::Vector2i mousePos)
{
    if(mousePos.x > posX && mousePos.x < posX+width)
        if(mousePos.y > posY && mousePos.y < posY+height)
        {
            return true;
        }
    return false;
}

bool element::isUnderMouse(sf::RenderWindow *window)
{
    sf::Vector2i mousePos=sf::Mouse::getPosition(*window);
    #ifdef DEBUG
    std::cout << mousePos.x << ":" << mousePos.y << "\n";
    #endif

    if(mousePos.x > posX && mousePos.x < posX+width)
        if(mousePos.y > posY && mousePos.y < posY+height)
        {
            return true;
        }
    return false;
}

void element::drawSprite(sf::RenderWindow *window)
{
    window->draw(image);
}

void element::drawLabel(sf::RenderWindow *window)
{
    window->draw(this->text);
}

void element::setID(int id)
{
    this->id=id;
}

int element::getID()
{
    return id;
}

sf::String element::ftoa(float i)
{
    char buffer[20];
    sprintf(buffer,"%-.1f",i);
    return sf::String(buffer);
}
