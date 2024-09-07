#ifndef TRIANGLESHAPE_H
#define TRIANGLESHAPE_H

#include "ShapeDecorator.h"

class TriangleDecorator : public ShapeDecorator 
{
private:
    sf::ConvexShape triangle;
public:
    TriangleDecorator(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3);
    void draw(sf::RenderWindow& window) override;
    float getPerimeter() const override;
    float getArea() const override;
};

#endif
