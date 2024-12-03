#ifndef TRIANGLECREATOR_H
#define TRIANGLECREATOR_H

#include "ShapeCreator.h"
#include "TriangleShape.h"
#include "MathShapeDecorator.h"
#include "TriangleShapeDecorator.h"
#include <sstream>
#include <memory>

class TriangleCreator : public ShapeCreator
{
private:
    TriangleCreator() {}

public:
    static TriangleCreator& getInstance()
    {
        static TriangleCreator instance;
        return instance;
    }

    TriangleCreator(const TriangleCreator&) = delete;
    void operator=(const TriangleCreator&) = delete;

    std::shared_ptr<MathShapeDecorator> CreateShape(const std::string& parameters) override
    {
        std::istringstream iss(parameters);
        int x1, y1, x2, y2, x3, y3;
        char temp;

        iss.ignore(4);
        iss >> x1 >> temp
            >> y1 >> temp >> temp >> temp >> temp
            >> x2 >> temp
            >> y2 >> temp >> temp >> temp >> temp
            >> x3 >> temp
            >> y3;

        auto triangleShape = std::make_shared<TriangleShape>(
            sf::Vector2f(static_cast<float>(x1), static_cast<float>(y1)),
            sf::Vector2f(static_cast<float>(x2), static_cast<float>(y2)),
            sf::Vector2f(static_cast<float>(x3), static_cast<float>(y3)));

        return std::make_shared<TriangleShapeDecorator>(triangleShape);
    }
};

#endif
