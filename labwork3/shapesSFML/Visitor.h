#ifndef VISITOR_H
#define VISITOR_H
#include <fstream>

#include "CircleShapeDecorator.h"
#include "RectangleShapeDecorator.h"
#include "TriangleShapeDecorator.h"

class Visitor 
{
public:
    virtual void Visit(CircleShapeDecorator& circle, std::ofstream& outf) = 0;
    virtual void Visit(RectangleShapeDecorator& rectangle, std::ofstream& outf) = 0;
    virtual void Visit(TriangleShapeDecorator& triangle, std::ofstream& outf) = 0;
    virtual ~Visitor() = default;
};

#endif