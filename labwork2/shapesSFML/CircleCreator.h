#ifndef CIRCLECREATOR_H
#define CIRCLECREATOR_H

#include "ShapeCreator.h"
#include "CircleShape.h"
#include <sstream>

class CircleCreator : public ShapeCreator 
{
private:
    CircleCreator() {} 

public:
    static CircleCreator& GetInstance()
    {
        static CircleCreator instance;
        return instance;
    }

    CircleCreator(const CircleCreator&) = delete;
    void operator=(const CircleCreator&) = delete;

    ShapeDecorator* CreateShape(const std::string& parameters) override 
    {
        std::istringstream iss(parameters);
        int cx, cy, r;
        char temp;
        iss.ignore(3);
        iss >> cx >> temp 
            >> cy >> temp >> temp >> temp 
            >> r;
        return new CircleDecorator(r, sf::Vector2f(cx, cy));
    }
};

#endif
