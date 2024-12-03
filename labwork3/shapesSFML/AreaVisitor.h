#ifndef AREAVISITOR_H
#define AREAVISITOR_H

#include "Visitor.h"
#include <iostream>

class AreaVisitor : public Visitor 
{
public:
    void Visit(CircleShapeDecorator& circle, std::ofstream& outf) override;
    void Visit(RectangleShapeDecorator& rectangle, std::ofstream& outf) override;
    void Visit(TriangleShapeDecorator& triangle, std::ofstream& outf) override;
};

#endif
