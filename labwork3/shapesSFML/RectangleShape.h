#ifndef RECTANGLESHAPE_H
#define RECTANGLESHAPE_H

#include <SFML/Graphics.hpp>
#include "Shape.h"

class RectangleShape : public Shape
{
private:
    sf::RectangleShape rectangle;

public:
    RectangleShape(sf::Vector2f size, sf::Vector2f position);
    void Draw(sf::RenderWindow& window) override;
    sf::RectangleShape& GetRectangleShape();
};

#endif
