#ifndef RECTANGLECREATOR_H
#define RECTANGLECREATOR_H

#include "ShapeCreator.h"
#include "RectangleShape.h"
#include "MathShapeDecorator.h"
#include "RectangleShapeDecorator.h"
#include <sstream>
#include <memory>

class RectangleCreator : public ShapeCreator
{
private:
    RectangleCreator() {}

public:
    static RectangleCreator& getInstance()
    {
        static RectangleCreator instance;
        return instance;
    }

    RectangleCreator(const RectangleCreator&) = delete;
    void operator=(const RectangleCreator&) = delete;

    std::shared_ptr<MathShapeDecorator> CreateShape(const std::string& parameters) override
    {
        std::istringstream iss(parameters);
        int x1, y1, x2, y2;
        char temp;

        iss.ignore(4); // Пропуск "x1="
        iss >> x1 >> temp
            >> y1 >> temp >> temp >> temp >> temp
            >> x2 >> temp
            >> y2;

        auto rectangleShape = std::make_shared<RectangleShape>(
            sf::Vector2f(static_cast<float>(x2 - x1), static_cast<float>(y2 - y1)),
            sf::Vector2f(static_cast<float>(x1), static_cast<float>(y1)));

        return std::make_shared<RectangleShapeDecorator>(rectangleShape);
    }
};

#endif
