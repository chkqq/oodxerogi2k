#ifndef AREAVISITOR_H
#define AREAVISITOR_H

#include "Visitor.h"
#include <iostream>

class AreaVisitor : public Visitor {
public:
    void visit(CircleDecorator& circle) override;
    void visit(RectangleDecorator& rectangle) override;
    void visit(TriangleDecorator& triangle) override;
};

#endif // AREAVISITOR_H
