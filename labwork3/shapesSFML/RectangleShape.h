#ifndef RECTANGLESHAPE_H
#define RECTANGLESHAPE_H

#include "ShapeDecorator.h"
#include <SFML/Graphics.hpp>
#include <fstream>

class RectangleDecorator : public ShapeDecorator 
{
private:
    sf::RectangleShape rectangle;

public:
    RectangleDecorator(sf::Vector2f size, sf::Vector2f position);
    void Draw(sf::RenderWindow& window) override;
    float GetPerimeter() const override;
    float GetArea() const override;

    void Accept(Visitor& visitor, std::ofstream& outf) override;
};

#endif // RECTANGLESHAPE_H
