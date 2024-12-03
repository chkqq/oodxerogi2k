#ifndef CIRCLESHAPEDECORATOR_H
#define CIRCLESHAPEDECORATOR_H

#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <cmath>
#include <fstream>
#include "MathShapeDecorator.h"
#include "CircleShape.h"

class CircleShapeDecorator : public MathShapeDecorator
{
public:
    explicit CircleShapeDecorator(std::shared_ptr<CircleShape> shape);
    void Accept(Visitor& visitor, std::ofstream& outf);
    float GetPerimeter() const override;
    float GetArea() const override;

private:
    std::shared_ptr<CircleShape> m_shape;
};

#endif