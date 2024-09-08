#include <SFML/Graphics.hpp>
#include "InputParser.h"
#include "PerimeterVisitor.h"
#include "AreaVisitor.h"
#include <fstream>

void processShapes(
    std::vector<ShapeDecorator*>& shapes, 
    PerimeterVisitor& perimeterVisitor, 
    AreaVisitor& areaVisitor,
    std::ofstream& outf
)
{
    for (auto& shape : shapes) 
    {
        shape->Accept(perimeterVisitor, outf);  // Вычисление и вывод периметра
        shape->Accept(areaVisitor, outf);       // Вычисление и вывод площади
    }
}

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

void renderShapes(std::vector<ShapeDecorator*>& shapes) 
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes Visualization");

    while (window.isOpen()) 
    {
        HandleEvents(window);
        DrawShapes(window, shapes);
    }
}

void cleanupShapes(std::vector<ShapeDecorator*>& shapes) 
{
    for (auto& shape : shapes)
    {
        delete shape;
    }
}

int main()
{
    std::vector<ShapeDecorator*> shapes = loadShapesFromFile("input.txt");
    std::ofstream outf("output.txt");
    PerimeterVisitor perimeterVisitor;
    AreaVisitor areaVisitor;

    processShapes(shapes, perimeterVisitor, areaVisitor, outf); 
    renderShapes(shapes);
    cleanupShapes(shapes);

    return 0;
}
//Внедрен паттерн «Посетитель», который отделяет логику вычисления и вывода площади и периметра от самих фигур.
//Добавлены два посетителя : один для вывода периметра, другой для площади.