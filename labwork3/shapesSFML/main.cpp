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
        shape->Accept(perimeterVisitor, outf);  // ���������� � ����� ���������
        shape->Accept(areaVisitor, outf);      // ���������� � ����� �������
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
    // �������� ����� �� �����
    auto shapes = loadShapesFromFile("input.txt");

    // �������� ����� ��� ������ �����������
    std::ofstream outf("output.txt");

    // �������� ����������� ��� ����������
    PerimeterVisitor perimeterVisitor;
    AreaVisitor areaVisitor;

    // ��������� �����
    processShapes(shapes, perimeterVisitor, areaVisitor, outf);

    // ������������ �����
    renderShapes(shapes);

    // ����� ��������� ������������� ����������� ������
    return 0;
}
