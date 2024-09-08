#include "PerimeterVisitor.h"
#include "CircleShape.h"
#include "RectangleShape.h"
#include "TriangleShape.h"

void PerimeterVisitor::Visit(CircleDecorator& circle, std::ofstream& outf) {
    outf << "CIRCLE: Perimeter = " << circle.GetPerimeter();
}

void PerimeterVisitor::Visit(RectangleDecorator& rectangle, std::ofstream& outf) {
    outf << "RECTANGLE: Perimeter = " << rectangle.GetPerimeter();
}

void PerimeterVisitor::Visit(TriangleDecorator& triangle, std::ofstream& outf) {
    outf << "TRIANGLE: Perimeter = " << triangle.GetPerimeter();
}
