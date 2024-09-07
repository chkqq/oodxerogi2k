#include "InputParser.h"
#include <fstream>
#include <sstream>

std::vector<ShapeDecorator*> loadShapesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<ShapeDecorator*> shapes;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;
        if (type == "CIRCLE:") {
            std::string parameters = line.substr(line.find(':') + 1);
            shapes.push_back(CircleCreator::getInstance().createShape(parameters));
        }
        else if (type == "RECTANGLE:") {
            std::string parameters = line.substr(line.find(':') + 1);
            shapes.push_back(RectangleCreator::getInstance().createShape(parameters));
        }
        else if (type == "TRIANGLE:") {
            std::string parameters = line.substr(line.find(':') + 1);
            shapes.push_back(TriangleCreator::getInstance().createShape(parameters));
        }
    }
    return shapes;
}

void saveResultsToFile(const std::vector<ShapeDecorator*>& shapes, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& shape : shapes) {
        if (dynamic_cast<CircleDecorator*>(shape)) {
            file << "CIRCLE: P=" << shape->getPerimeter() << "; S=" << shape->getArea() << "\n";
        }
        else if (dynamic_cast<RectangleDecorator*>(shape)) {
            file << "RECTANGLE: P=" << shape->getPerimeter() << "; S=" << shape->getArea() << "\n";
        }
        else if (dynamic_cast<TriangleDecorator*>(shape)) {
            file << "TRIANGLE: P=" << shape->getPerimeter() << "; S=" << shape->getArea() << "\n";
        }
    }
}
