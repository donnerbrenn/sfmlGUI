#include "vector2f.h"

vector2f::vector2f()
{
    x=0;
    y=0;
}

vector2f::vector2f(float x, float y)
{
    this->x=x;
    this->y=y;
}

float vector2f::length()
{
    return(sqrt(x*x+y*y));
}


float vector2f::getDotProduct(sf::Vector2f other)
{
    return x * other.x + y * other.y;
}
float vector2f::getCrossProduct(sf::Vector2f other)
{
    return x*other.y - y*other.x;
}

void vector2f::normalize()
{
    div(length());
}

vector2f vector2f::getNormalized()
{
    vector2f result(x,y);
    result.normalize();
    return result;
}

void vector2f::add(float value)
{
    x+=value;
    y+=value;
}

void vector2f::add(float x, float y)
{
    this->x+=x;
    this->y+=y;
}

void vector2f::add(sf::Vector2f value)
{
    add(value.x,value.y);
}

void vector2f::sub(float value)
{
    x-=value;
    y-=value;
}

void vector2f::sub(float x, float y)
{
    this->x-=x;
    this->y-=y;

}

void vector2f::sub(sf::Vector2f value)
{
    sub(sf::Vector2f(value.x,value.y));
}

void vector2f::mul(float value)
{
    x*=value;
    y*=value;
}

void vector2f::div(float value)
{
    x/=value;
    y/=value;
}

vector2f vector2f::operator+=(sf::Vector2f value)
{
    add(value);
    return *this;
}

vector2f vector2f::operator-=(sf::Vector2f value)
{
    sub(value);
    return *this;
}

vector2f vector2f::operator*=(float value)
{
    mul(value);
    return *this;
}

vector2f vector2f::operator/=(float value)
{
    div(value);
    return *this;
}

 vector2f vector2f::operator+=(float value)
 {
    add(value);
    return *this;
 }

  vector2f vector2f::operator-=(float value)
  {
    sub(value);
    return *this;
  }

    vector2f vector2f::operator+(sf::Vector2f other)
    {
        vector2f result=vector2f(x,y);
        result+=other;
        return result;
    }

    vector2f vector2f::operator+(float value)
    {
        vector2f result=vector2f(x,y);
        result+=value;
        return result;
    }

    vector2f vector2f::operator-(sf::Vector2f other)
    {
        vector2f result=vector2f(x,y);
        result-=other;
        return result;        
    }

    vector2f vector2f::operator-(float value)
    {
        vector2f result=vector2f(x,y);
        result-=value;
        return result;
    }

    vector2f vector2f::operator*(float value)
    {
        vector2f result=vector2f(x,y);
        result*=value;
        return result;
    }

    vector2f vector2f::operator/(float value)
    {
        vector2f result=vector2f(x,y);
        result/=value;
        return result;
    }

    void vector2f::operator=(sf::Vector2f other)
    {
        x=other.x;
        y=other.y;
    }