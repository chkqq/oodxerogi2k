#ifndef TRIANGLESHAPE_H
#define TRIANGLESHAPE_H

#include <SFML/Graphics.hpp>
#include "Shape.h"

class TriangleShape : public Shape
{
private:
    sf::ConvexShape triangle;

public:
    TriangleShape(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3);
    void Draw(sf::RenderWindow& window) override;
    sf::ConvexShape& GetTriangleShape();
};

#endif
