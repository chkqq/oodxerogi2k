#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <vector>
#include <string>
#include "ShapeDecorator.h"
#include "CircleCreator.h"
#include "RectangleCreator.h"
#include "TriangleCreator.h"

std::vector<ShapeDecorator*> loadShapesFromFile(const std::string& filename);
void saveResultsToFile(const std::vector<ShapeDecorator*>& shapes, const std::string& filename);

#endif
