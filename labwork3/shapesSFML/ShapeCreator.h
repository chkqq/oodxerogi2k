#ifndef SHAPECREATOR_H
#define SHAPECREATOR_H

#include "ShapeDecorator.h"

class ShapeCreator {
public:
    virtual ShapeDecorator* createShape(const std::string& parameters) = 0;
    virtual ~ShapeCreator() = default;
};

#endif