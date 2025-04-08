#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <cmath>
#include <time.h>

class Shape {
private:
    std::shared_ptr<sf::RectangleShape> rect;
    std::string name;
    sf::Vector2f pos;
    float width, height;
public:
    Shape(
        std::string name, 
        sf::Vector2f pos, 
        float width, 
        float height, 
        int red, 
        int green, 
        int blue
    );

    void draw(std::shared_ptr<sf::RenderWindow> window);

    std::shared_ptr<sf::RectangleShape> getRect();
    std::string getName();
    float getWidth();
    float getHeight();
};

#endif