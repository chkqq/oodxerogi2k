#include <SFML/Graphics.hpp>
#include "InputParser.h"
#include "PerimeterVisitor.h"
#include "AreaVisitor.h"
#include <fstream>
#include <memory>

void processShapes(
    const std::vector<std::shared_ptr<MathShapeDecorator>>& shapes,
    PerimeterVisitor& perimeterVisitor,
    AreaVisitor& areaVisitor,
    std::ofstream& outf
)
{
    for (const auto& shape : shapes)
    {
        shape->Accept(perimeterVisitor, outf);  // Вычисление и вывод периметра
        shape->Accept(areaVisitor, outf);      // Вычисление и вывод площади
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

void DrawShapes(sf::RenderWindow& window, const std::vector<std::shared_ptr<MathShapeDecorator>>& shapes)
{
    window.clear();
    for (const auto& shape : shapes)
    {
        shape->Draw(window);
    }
    window.display();
}

void renderShapes(const std::vector<std::shared_ptr<MathShapeDecorator>>& shapes)
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
    // Загрузка фигур из файла
    auto shapes = loadShapesFromFile("input.txt");

    // Открытие файла для вывода результатов
    std::ofstream outf("output.txt");

    // Создание посетителей для вычислений
    PerimeterVisitor perimeterVisitor;
    AreaVisitor areaVisitor;

    // Обработка фигур
    processShapes(shapes, perimeterVisitor, areaVisitor, outf);

    // Визуализация фигур
    renderShapes(shapes);

    // Умные указатели автоматически освобождают память
    return 0;
}
