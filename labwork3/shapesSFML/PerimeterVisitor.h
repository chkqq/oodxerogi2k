#ifndef PERIMETERVISITOR_H
#define PERIMETERVISITOR_H

#include "Visitor.h"
#include <iostream>

class PerimeterVisitor : public Visitor 
{
public:
    void Visit(CircleDecorator& circle, std::ofstream& outf) override;
    void Visit(RectangleDecorator& rectangle, std::ofstream& outf) override;
    void Visit(TriangleDecorator& triangle, std::ofstream& outf) override;
};

#endif
