#include "TriangleShape.h"
#include "Visitor.h"

TriangleDecorator::TriangleDecorator(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3) {
    triangle.setPointCount(3);
    triangle.setPoint(0, point1);
    triangle.setPoint(1, point2);
    triangle.setPoint(2, point3);
    triangle.setFillColor(sf::Color::Green);
    triangle.setOutlineColor(sf::Color::Green);
    triangle.setOutlineThickness(2);
}

void TriangleDecorator::draw(sf::RenderWindow& window) {
    window.draw(triangle);
}

float TriangleDecorator::getPerimeter() const {
    float side1 = std::sqrt(std::pow(triangle.getPoint(1).x - triangle.getPoint(0).x, 2) +
        std::pow(triangle.getPoint(1).y - triangle.getPoint(0).y, 2));
    float side2 = std::sqrt(std::pow(triangle.getPoint(2).x - triangle.getPoint(1).x, 2) +
        std::pow(triangle.getPoint(2).y - triangle.getPoint(1).y, 2));
    float side3 = std::sqrt(std::pow(triangle.getPoint(0).x - triangle.getPoint(2).x, 2) +
        std::pow(triangle.getPoint(0).y - triangle.getPoint(2).y, 2));
    return side1 + side2 + side3;
}

float TriangleDecorator::getArea() const {
    return std::abs(triangle.getPoint(0).x * (triangle.getPoint(1).y - triangle.getPoint(2).y) +
        triangle.getPoint(1).x * (triangle.getPoint(2).y - triangle.getPoint(0).y) +
        triangle.getPoint(2).x * (triangle.getPoint(0).y - triangle.getPoint(1).y)) / 2.0f;
}

void TriangleDecorator::accept(Visitor& visitor) {
    visitor.visit(*this);
}
