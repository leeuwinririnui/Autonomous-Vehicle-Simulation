#include "shape.h"

Shape::Shape(
    std::string name, 
    sf::Vector2f pos, 
    float width, 
    float height, 
    int red, 
    int green, 
    int blue
) {
    this->name = name;
    this->width = width;
    this->height = height;
    rect = std::make_shared<sf::RectangleShape>(sf::Vector2f(width, height));
    rect->setFillColor(sf::Color(red, green, blue));    
    rect->setPosition(pos);
}

void Shape::draw(std::shared_ptr<sf::RenderWindow> window) {
    if (rect) {
        window->draw(*rect);
    }
}

std::shared_ptr<sf::RectangleShape> Shape::getRect() { return rect; }
std::string Shape::getName() { return name; }
float Shape::getWidth() { return width; }
float Shape::getHeight() { return height; }
