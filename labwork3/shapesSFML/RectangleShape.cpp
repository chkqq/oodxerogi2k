#include "RectangleShape.h"
#include "Visitor.h"

RectangleShape::RectangleShape(sf::Vector2f size, sf::Vector2f position)
{
    rectangle.setSize(size);
    rectangle.setPosition(position);
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setOutlineColor(sf::Color::Blue);
    rectangle.setOutlineThickness(2);
}

void RectangleShape::Draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}

sf::RectangleShape& RectangleShape::GetRectangleShape()
{
    return rectangle;
}
