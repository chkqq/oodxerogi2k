#include "InputParser.h"
#include <fstream>
#include <sstream>

std::vector<std::shared_ptr<MathShapeDecorator>> loadShapesFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    std::vector<std::shared_ptr<MathShapeDecorator>> shapes;
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "CIRCLE:")
        {
            std::string parameters = line.substr(line.find(':') + 1);
            shapes.push_back(CircleCreator::getInstance().CreateShape(parameters));
        }
        else if (type == "RECTANGLE:")
        {
            std::string parameters = line.substr(line.find(':') + 1);
            shapes.push_back(RectangleCreator::getInstance().CreateShape(parameters));
        }
        else if (type == "TRIANGLE:")
        {
            std::string parameters = line.substr(line.find(':') + 1);
            shapes.push_back(TriangleCreator::getInstance().CreateShape(parameters));
        }
    }

    return shapes;
}
