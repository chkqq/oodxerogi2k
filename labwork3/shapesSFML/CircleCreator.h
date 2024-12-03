#ifndef CIRCLECREATOR_H
#define CIRCLECREATOR_H

#include "ShapeCreator.h"
#include "CircleShape.h"
#include "MathShapeDecorator.h"
#include <sstream>
#include <memory>

class CircleCreator : public ShapeCreator
{
private:
    CircleCreator() {}

public:
    static CircleCreator& getInstance()
    {
        static CircleCreator instance;
        return instance;
    }

    CircleCreator(const CircleCreator&) = delete;
    void operator=(const CircleCreator&) = delete;

    std::shared_ptr<MathShapeDecorator> CreateShape(const std::string& parameters) override
    {
        std::istringstream iss(parameters);
        int cx, cy, r;
        char temp;

        iss.ignore(3);
        iss >> cx >> temp
            >> cy >> temp >> temp >> temp
            >> r;
        auto circleShape = std::make_shared<CircleShape>(
            static_cast<float>(r),
            sf::Vector2f(static_cast<float>(cx), static_cast<float>(cy)));
        return std::make_shared<CircleShapeDecorator>(circleShape);
    }
};

#endif
