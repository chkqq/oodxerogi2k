#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include <SFML/Graphics.hpp>
#include "ShapeDecorator.h"

class CircleDecorator : public ShapeDecorator {
private:
    sf::CircleShape circle;

public:
    CircleDecorator(float radius, sf::Vector2f position);
    void draw(sf::RenderWindow& window) override;
    float getPerimeter() const override;
    float getArea() const override;

    void accept(Visitor& visitor) override;
};

#endif // CIRCLESHAPE_H
