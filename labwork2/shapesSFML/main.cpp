#include <SFML/Graphics.hpp>
#include "InputParser.h"

void HandleEvents(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) 
        {
            window.close();
        }
    }
}

void DrawShapes(sf::RenderWindow& window, const std::vector<ShapeDecorator*>& shapes) 
{
    window.clear();
    for (auto& shape : shapes) 
    {
        shape->Draw(window);
    }
    window.display();
}

void CleanUpShapes(std::vector<ShapeDecorator*>& shapes)
{
    for (auto& shape : shapes) 
    {
        delete shape;
    }
    shapes.clear();
}

void renderShapes(std::vector<ShapeDecorator*>& shapes)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes Visualization");

    while (window.isOpen())
    {
        HandleEvents(window);
        DrawShapes(window, shapes);
    }
}


int main() 
{
    std::vector<ShapeDecorator*> shapes = LoadShapesFromFile("input.txt");

    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes Visualization");
    SaveResultsToFile(shapes, "output.txt");
    renderShapes(shapes);
    CleanUpShapes(shapes);

    return 0;
}