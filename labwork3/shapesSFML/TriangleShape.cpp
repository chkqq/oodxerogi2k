#include "TriangleShape.h"
#include "Visitor.h"

TriangleShape::TriangleShape(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3)
{
    triangle.setPointCount(3);
    triangle.setPoint(0, point1);
    triangle.setPoint(1, point2);
    triangle.setPoint(2, point3);
    triangle.setFillColor(sf::Color::Green);
    triangle.setOutlineColor(sf::Color::Green);
    triangle.setOutlineThickness(2);
}

void TriangleShape::Draw(sf::RenderWindow& window)
{
    window.draw(triangle);
}

sf::ConvexShape& TriangleShape::GetTriangleShape()
{
    return triangle;
}
