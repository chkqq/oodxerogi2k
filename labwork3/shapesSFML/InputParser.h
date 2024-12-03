#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <vector>
#include <string>
#include <memory>
#include "MathShapeDecorator.h"
#include "CircleCreator.h"
#include "RectangleCreator.h"
#include "TriangleCreator.h"

std::vector<std::shared_ptr<MathShapeDecorator>> loadShapesFromFile(const std::string& filename);

#endif
