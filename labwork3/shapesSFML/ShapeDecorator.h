#ifndef SHAPEDECORATOR_H
#define SHAPEDECORATOR_H

#include <SFML/Graphics.hpp>
#include "Visitor.h"

class ShapeDecorator 
{
public:
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual float getPerimeter() const = 0;
    virtual float getArea() const = 0;
    virtual void accept(Visitor& visitor) = 0;
    virtual ~ShapeDecorator() = default;
};

#endif
