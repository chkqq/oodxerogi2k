#include "PerimeterVisitor.h"
#include "CircleShapeDecorator.h"
#include "RectangleShapeDecorator.h"
#include "TriangleShapeDecorator.h"

void PerimeterVisitor::Visit(CircleShapeDecorator& circle, std::ofstream& outf) {
    outf << "CIRCLE: Perimeter = " << circle.GetPerimeter();
}

void PerimeterVisitor::Visit(RectangleShapeDecorator& rectangle, std::ofstream& outf) {
    outf << "RECTANGLE: Perimeter = " << rectangle.GetPerimeter();
}

void PerimeterVisitor::Visit(TriangleShapeDecorator& triangle, std::ofstream& outf) {
    outf << "TRIANGLE: Perimeter = " << triangle.GetPerimeter();
}
