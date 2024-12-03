#include "TriangleShapeDecorator.h"

TriangleShapeDecorator::TriangleShapeDecorator(std::shared_ptr<TriangleShape> shape)
    : m_shape(shape)
{
}

float TriangleShapeDecorator::GetPerimeter() const
{
    const auto& triangle = m_shape->GetTriangleShape();
    sf::Vector2f p1 = triangle.getPoint(0);
    sf::Vector2f p2 = triangle.getPoint(1);
    sf::Vector2f p3 = triangle.getPoint(2);

    auto distance = [](sf::Vector2f a, sf::Vector2f b) {
        return std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2));
    };

    return distance(p1, p2) + distance(p2, p3) + distance(p3, p1);
}

float TriangleShapeDecorator::GetArea() const
{
    const auto& triangle = m_shape->GetTriangleShape();
    sf::Vector2f p1 = triangle.getPoint(0);
    sf::Vector2f p2 = triangle.getPoint(1);
    sf::Vector2f p3 = triangle.getPoint(2);

    return 0.5f * std::abs(
        p1.x * (p2.y - p3.y) +
        p2.x * (p3.y - p1.y) +
        p3.x * (p1.y - p2.y));
}

void TriangleShapeDecorator::Accept(Visitor& visitor, std::ofstream& outf)
{
    visitor.Visit(*this, outf);
}