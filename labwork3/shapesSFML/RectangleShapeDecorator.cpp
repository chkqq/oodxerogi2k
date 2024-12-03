#include "RectangleShapeDecorator.h"

RectangleShapeDecorator::RectangleShapeDecorator(std::shared_ptr<RectangleShape> shape)
    : m_shape(shape)
{
}

float RectangleShapeDecorator::GetPerimeter() const
{
    const auto& rectangle = m_shape->GetRectangleShape();
    return 2 * (rectangle.getSize().x + rectangle.getSize().y);
}

float RectangleShapeDecorator::GetArea() const
{
    const auto& rectangle = m_shape->GetRectangleShape();
    return rectangle.getSize().x * rectangle.getSize().y;
}

void RectangleShapeDecorator::Accept(Visitor& visitor, std::ofstream& outf)
{
    visitor.Visit(*this, outf);
}