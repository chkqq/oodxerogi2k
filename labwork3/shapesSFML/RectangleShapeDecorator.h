#ifndef RECTANGLESHAPEDECORATOR_H
#define RECTANGLESHAPEDECORATOR_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <fstream>
#include "MathShapeDecorator.h"
#include "RectangleShape.h"

class RectangleShapeDecorator : public MathShapeDecorator
{
public:
    explicit RectangleShapeDecorator(std::shared_ptr<RectangleShape> shape);
    void Accept(Visitor& visitor, std::ofstream& outf);
    float GetPerimeter() const override;
    float GetArea() const override;

private:
    std::shared_ptr<RectangleShape> m_shape;
};

#endif
