#ifndef PERIMETERVISITOR_H
#define PERIMETERVISITOR_H

#include "Visitor.h"
#include <iostream>

class PerimeterVisitor : public Visitor 
{
public:
    void Visit(CircleShapeDecorator& circle, std::ofstream& outf) override;
    void Visit(RectangleShapeDecorator& rectangle, std::ofstream& outf) override;
    void Visit(TriangleShapeDecorator& triangle, std::ofstream& outf) override;
};

#endif
