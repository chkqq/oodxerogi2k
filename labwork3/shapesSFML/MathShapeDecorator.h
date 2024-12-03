#ifndef MATHSHAPEDECORATOR_H
#define MATHSHAPEDECORATOR_H

#include <SFML/Graphics.hpp>
#include "Shape.h"
#include "Visitor.h"

class MathShapeDecorator : public Shape
{
public:
    virtual float GetPerimeter() const = 0;
    virtual float GetArea() const = 0;

    virtual void Draw(sf::RenderWindow& window) = 0;
    virtual void Accept(Visitor& visitor, std::ofstream& outf) = 0;
private:
    std::shared_ptr<Shape> m_shape;
};

#endif
