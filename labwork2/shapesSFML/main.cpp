#include <SFML/Graphics.hpp>
#include "InputParser.h"

int main() {
    std::vector<ShapeDecorator*> shapes = loadShapesFromFile("input.txt");

    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes Visualization");
    saveResultsToFile(shapes, "output.txt");

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
