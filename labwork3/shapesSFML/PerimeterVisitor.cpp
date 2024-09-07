#include "PerimeterVisitor.h"
#include "CircleShape.h"
#include "RectangleShape.h"
#include "TriangleShape.h"

void PerimeterVisitor::visit(CircleDecorator& circle) {
    std::cout << "CIRCLE: Perimeter = " << circle.getPerimeter() << std::endl;
}

void PerimeterVisitor::visit(RectangleDecorator& rectangle) {
    std::cout << "RECTANGLE: Perimeter = " << rectangle.getPerimeter() << std::endl;
}

void PerimeterVisitor::visit(TriangleDecorator& triangle) {
    std::cout << "TRIANGLE: Perimeter = " << triangle.getPerimeter() << std::endl;
}
