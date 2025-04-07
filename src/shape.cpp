#include "core.h"

Shape::Shape(std::string name, int x, int y, float width, float height, int red, int green, int blue) {
    this->name = name;
    this->width = width;
    this->height = height;

    rect = std::make_shared<sf::RectangleShape>(sf::Vector2f(width, height));
    rect->setFillColor(sf::Color(red, green, blue));    
    rect->setPosition(x, y);
}

void Shape::draw(std::shared_ptr<sf::RenderWindow> window) {
    if (rect) {
        window->draw(*rect);
    }
}