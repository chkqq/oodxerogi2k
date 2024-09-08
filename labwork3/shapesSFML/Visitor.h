#ifndef VISITOR_H
#define VISITOR_H
#include <fstream>

class CircleDecorator;
class RectangleDecorator;
class TriangleDecorator;
class Visitor 
{
public:
    virtual void Visit(CircleDecorator& circle, std::ofstream& outf) = 0;
    virtual void Visit(RectangleDecorator& rectangle, std::ofstream& outf) = 0;
    virtual void Visit(TriangleDecorator& triangle, std::ofstream& outf) = 0;
    virtual ~Visitor() = default;
};

#endif