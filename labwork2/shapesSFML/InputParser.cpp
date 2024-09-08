#include "InputParser.h"
#include <fstream>
#include <sstream>

std::vector<ShapeDecorator*> LoadShapesFromFile(const std::string& filename) 
{
    std::ifstream file(filename);
    std::vector<ShapeDecorator*> shapes;
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string type;
        iss >> type;
        if (type == "CIRCLE:")
        {
            std::string parameters = line.substr(line.find(':') + 1);
            shapes.push_back(CircleCreator::GetInstance().CreateShape(parameters));
        }
        else if (type == "RECTANGLE:") 
        {
            std::string parameters = line.substr(line.find(':') + 1);
            shapes.push_back(RectangleCreator::GetInstance().CreateShape(parameters));
        }
        else if (type == "TRIANGLE:") 
        {
            std::string parameters = line.substr(line.find(':') + 1);
            shapes.push_back(TriangleCreator::GetInstance().CreateShape(parameters));
        }
    }
    return shapes;
}

void SaveResultsToFile(const std::vector<ShapeDecorator*>& shapes, const std::string& filename) 
{
    std::ofstream file(filename);
    for (const auto& shape : shapes) 
    {
        if (dynamic_cast<CircleDecorator*>(shape))
        {
            file << "CIRCLE: P=" << shape->GetPerimeter() << "; S=" << shape->GetArea() << "\n";
        }
        else if (dynamic_cast<RectangleDecorator*>(shape)) 
        {
            file << "RECTANGLE: P=" << shape->GetPerimeter() << "; S=" << shape->GetArea() << "\n";
        }
        else if (dynamic_cast<TriangleDecorator*>(shape)) 
        {
            file << "TRIANGLE: P=" << shape->GetPerimeter() << "; S=" << shape->GetArea() << "\n";
        }
    }
}
