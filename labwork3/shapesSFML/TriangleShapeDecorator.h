#ifndef TRIANGLESHAPEDECORATOR_H
#define TRIANGLESHAPEDECORATOR_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <fstream>
#include "MathShapeDecorator.h"
#include "TriangleShape.h"

class TriangleShapeDecorator : public MathShapeDecorator
{
public:
    explicit TriangleShapeDecorator(std::shared_ptr<TriangleShape> shape);
    void Accept(Visitor& visitor, std::ofstream& outf);
    float GetPerimeter() const override;
    float GetArea() const override;

private:
    std::shared_ptr<TriangleShape> m_shape;
};

#endif
