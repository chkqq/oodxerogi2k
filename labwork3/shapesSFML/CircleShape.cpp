#include "CircleShape.h"
#include "Visitor.h"

CircleDecorator::CircleDecorator(float radius, sf::Vector2f position) {
    circle.setRadius(radius);
    circle.setPosition(position);
    circle.setFillColor(sf::Color::Red);
    circle.setOutlineColor(sf::Color::Red);
    circle.setOutlineThickness(2);
}

void CircleDecorator::draw(sf::RenderWindow& window) {
    window.draw(circle);
}

float CircleDecorator::getPerimeter() const {
    return 2 * 3.14159f * circle.getRadius();
}

float CircleDecorator::getArea() const {
    return 3.14159f * std::pow(circle.getRadius(), 2);
}

void CircleDecorator::accept(Visitor& visitor) {
    visitor.visit(*this);
}
