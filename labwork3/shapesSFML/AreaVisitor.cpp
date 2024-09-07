#include "AreaVisitor.h"
#include "CircleShape.h"
#include "RectangleShape.h"
#include "TriangleShape.h"

void AreaVisitor::visit(CircleDecorator& circle) {
    std::cout << "CIRCLE: Area = " << circle.getArea() << std::endl;
}

void AreaVisitor::visit(RectangleDecorator& rectangle) {
    std::cout << "RECTANGLE: Area = " << rectangle.getArea() << std::endl;
}

void AreaVisitor::visit(TriangleDecorator& triangle) {
    std::cout << "TRIANGLE: Area = " << triangle.getArea() << std::endl;
}
