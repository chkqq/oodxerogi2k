#include <SFML/Graphics.hpp>
#include "InputParser.h"
#include "PerimeterVisitor.h"
#include "AreaVisitor.h"

int main() {
    std::vector<ShapeDecorator*> shapes = loadShapesFromFile("input.txt");

    PerimeterVisitor perimeterVisitor;
    AreaVisitor areaVisitor;

    for (auto& shape : shapes) {
        shape->accept(perimeterVisitor);  // Вычисление и вывод периметра
        shape->accept(areaVisitor);       // Вычисление и вывод площади
    }

    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes Visualization");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (auto& shape : shapes) {
            shape->draw(window);
        }
        window.display();
    }

    for (auto& shape : shapes) {
        delete shape;
    }

    return 0;
}
//Внедрен паттерн «Посетитель», который отделяет логику вычисления и вывода площади и периметра от самих фигур.
//Добавлены два посетителя : один для вывода периметра, другой для площади.