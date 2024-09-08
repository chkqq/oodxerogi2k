#ifndef AREAVISITOR_H
#define AREAVISITOR_H

#include "Visitor.h"
#include <iostream>

class AreaVisitor : public Visitor 
{
public:
    void Visit(CircleDecorator& circle, std::ofstream& outf) override;
    void Visit(RectangleDecorator& rectangle, std::ofstream& outf) override;
    void Visit(TriangleDecorator& triangle, std::ofstream& outf) override;
};

#endif
