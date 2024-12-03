#include "MathShapeDecorator.h"

void MathShapeDecorator::Draw(sf::RenderWindow& window)
{
    m_shape->Draw(window);
}

void MathShapeDecorator::Accept(Visitor& visitor, std::ofstream& outf)
{
    m_shape->Accept(visitor, outf);
}
