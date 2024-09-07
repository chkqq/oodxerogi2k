#ifndef VISITOR_H
#define VISITOR_H

class CircleDecorator;
class RectangleDecorator;
class TriangleDecorator;

class Visitor {
public:
    virtual void visit(CircleDecorator& circle) = 0;
    virtual void visit(RectangleDecorator& rectangle) = 0;
    virtual void visit(TriangleDecorator& triangle) = 0;
    virtual ~Visitor() = default;
};

#endif // VISITOR_H
