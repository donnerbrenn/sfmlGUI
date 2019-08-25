#pragma once
#include <SFML/System.hpp>
#include <math.h>

class vector2f : public sf::Vector2f
{
public:
    vector2f();
    vector2f(float x, float y);
    vector2f(sf::Vector2u value);
    vector2f(sf::Vector2i value);
    float length();
    float getDotProduct(sf::Vector2f other);
    float getCrossProduct(sf::Vector2f other);
    void normalize();
    vector2f getNormalized();

    vector2f operator+=(sf::Vector2f value);
    vector2f operator+=(float value);
    vector2f operator-=(sf::Vector2f value);
    vector2f operator-=(float value);
    vector2f operator*=(float value);
    vector2f operator/=(float value);
    void operator*=(sf::Vector2f other);
    void operator/=(sf::Vector2f other);

    vector2f operator+(sf::Vector2f other);
    vector2f operator+(float value);
    vector2f operator-(sf::Vector2f other);
    vector2f operator-(float value);
    vector2f operator*(float value);
    vector2f operator/(float value);

    void operator=(sf::Vector2f other);


protected:
    void add(float value);
    void add(float x, float y);
    void add(sf::Vector2f value);

    void sub(float value);
    void sub(float x, float y);
    void sub(sf::Vector2f value);

    void mul(float value);
    void div(float value);
};
