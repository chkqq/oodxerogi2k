#ifndef SHAPECREATOR_H
#define SHAPECREATOR_H

#include <memory>
#include "mATHShapeDecorator.h"

class ShapeCreator
{
public:
    virtual std::shared_ptr<MathShapeDecorator> CreateShape(const std::string& parameters) = 0;
    virtual ~ShapeCreator() = default;
};

#endif
