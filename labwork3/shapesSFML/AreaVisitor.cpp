#include "AreaVisitor.h"
#include "CircleShapeDecorator.h"
#include "RectangleShapeDecorator.h"
#include "TriangleShapeDecorator.h"

void AreaVisitor::Visit(CircleShapeDecorator& circle, std::ofstream& outf)
{
    outf << ", Area = " << circle.GetArea() << std::endl;
}

void AreaVisitor::Visit(RectangleShapeDecorator& rectangle, std::ofstream& outf)
{
    outf << ", Area = " << rectangle.GetArea() << std::endl;
}

void AreaVisitor::Visit(TriangleShapeDecorator& triangle, std::ofstream& outf)
{
    outf << ", Area = " << triangle.GetArea() << std::endl;
}
