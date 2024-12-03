#include "CircleShape.h"
#include "Visitor.h"

CircleShape::CircleShape(float radius, sf::Vector2f position)
{
    circle.setRadius(radius);
    circle.setPosition(position);
    circle.setFillColor(sf::Color::Red);
    circle.setOutlineColor(sf::Color::Red);
    circle.setOutlineThickness(2);
}

void CircleShape::Draw(sf::RenderWindow& window)
{
    window.draw(circle);
}

sf::CircleShape& CircleShape::GetCircleShape()
{
    return circle;
}

