#ifndef RECTANGLECREATOR_H
#define RECTANGLECREATOR_H

#include "ShapeCreator.h"
#include "RectangleShape.h"
#include <sstream>

class RectangleCreator : public ShapeCreator
{
private:
    RectangleCreator() {}

public:
    static RectangleCreator& GetInstance() 
    {
        static RectangleCreator instance;
        return instance;
    }

    RectangleCreator(const RectangleCreator&) = delete;
    void operator=(const RectangleCreator&) = delete;

    ShapeDecorator* CreateShape(const std::string& parameters) override 
    {
        std::istringstream iss(parameters);
        int x1, y1, x2, y2;
        char temp;
        iss.ignore(4);
        iss >> x1 >> temp
            >> y1 >> temp >> temp >> temp >> temp 
            >> x2 >> temp
            >> y2;
        return new RectangleDecorator(sf::Vector2f(x2 - x1, y2 - y1), sf::Vector2f(x1, y1));
    }
};

#endif
