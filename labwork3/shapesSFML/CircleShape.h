#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include <SFML/Graphics.hpp>
#include "Shape.h"

class CircleShape : public Shape 
{
private:
    sf::CircleShape circle;

public:
    CircleShape(float radius, sf::Vector2f position);
    void Draw(sf::RenderWindow& window) override;
    sf::CircleShape& GetCircleShape();
};

#endif
