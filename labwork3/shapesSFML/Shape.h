#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>
#include "Visitor.h"
#include <memory>
class Shape 
{
public:
    virtual void Draw(sf::RenderWindow& window) = 0;
    virtual ~Shape() = default;
};

#endif
