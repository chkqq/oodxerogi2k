#include "CircleShapeDecorator.h"

CircleShapeDecorator::CircleShapeDecorator(std::shared_ptr<CircleShape> shape)
    : m_shape(shape)
{
}

float CircleShapeDecorator::GetPerimeter() const
{
    return 2 * M_PI * m_shape->GetCircleShape().getRadius();
}

float CircleShapeDecorator::GetArea() const
{
    return M_PI * std::pow(m_shape->GetCircleShape().getRadius(), 2);
}

void CircleShapeDecorator::Accept(Visitor& visitor, std::ofstream& outf)
{
    visitor.Visit(*this, outf);
}