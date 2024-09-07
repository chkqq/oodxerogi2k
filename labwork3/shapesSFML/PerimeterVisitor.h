#ifndef PERIMETERVISITOR_H
#define PERIMETERVISITOR_H

#include "Visitor.h"
#include <iostream>

class PerimeterVisitor : public Visitor {
public:
    void visit(CircleDecorator& circle) override;
    void visit(RectangleDecorator& rectangle) override;
    void visit(TriangleDecorator& triangle) override;
};

#endif
