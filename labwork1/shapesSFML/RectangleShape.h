#ifndef RECTANGLESHAPE_H
#define RECTANGLESHAPE_H

#include "ShapeDecorator.h"

class RectangleDecorator : public ShapeDecorator {
private:
    sf::RectangleShape rectangle;
public:
    RectangleDecorator(sf::Vector2f size, sf::Vector2f position);
    void draw(sf::RenderWindow& window) override;
    float getPerimeter() const override;
    float getArea() const override;
};

#endif
