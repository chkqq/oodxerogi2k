#ifndef TRIANGLECREATOR_H
#define TRIANGLECREATOR_H

#include "ShapeCreator.h"
#include "TriangleShape.h"
#include <sstream>

class TriangleCreator : public ShapeCreator {
private:
    TriangleCreator() {}

public:
    static TriangleCreator& getInstance() {
        static TriangleCreator instance;
        return instance;
    }

    TriangleCreator(const TriangleCreator&) = delete;
    void operator=(const TriangleCreator&) = delete;

    ShapeDecorator* createShape(const std::string& parameters) override {
        std::istringstream iss(parameters);
        int x1, y1, x2, y2, x3, y3;
        char temp;
        iss.ignore(4);
        iss >> x1 >> temp >> y1 >> temp >> temp >> temp >> temp >> x2 >> temp >> y2 >> temp >> temp >> temp >> temp >> x3 >> temp >> y3;
        return new TriangleDecorator(sf::Vector2f(x1, y1), sf::Vector2f(x2, y2), sf::Vector2f(x3, y3));
    }
};

#endif
