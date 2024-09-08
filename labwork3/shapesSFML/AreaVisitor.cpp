#include "AreaVisitor.h"
#include "CircleShape.h"
#include "RectangleShape.h"
#include "TriangleShape.h"

void AreaVisitor::Visit(CircleDecorator& circle, std::ofstream& outf)
{
    outf << ", Area = " << circle.GetArea() << std::endl;
}

void AreaVisitor::Visit(RectangleDecorator& rectangle, std::ofstream& outf)
{
    outf << ", Area = " << rectangle.GetArea() << std::endl;
}

void AreaVisitor::Visit(TriangleDecorator& triangle, std::ofstream& outf)
{
    outf << ", Area = " << triangle.GetArea() << std::endl;
}
