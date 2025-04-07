#ifndef CORE_H
#define CORE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

class Shape {
private:
    std::shared_ptr<sf::RectangleShape> rect;
    std::string name;
    float width, height;
public:
    Shape(std::string name, int x, int y, float width, float height, int red, int green, int blue);

    void draw(std::shared_ptr<sf::RenderWindow> window);

    std::shared_ptr<sf::RectangleShape> getRect() { return rect; }
    std::string getName() { return name; }
    float getWidth() { return width; }
    float getHeight() { return height; }
};

class Vehicle : public Shape {
private:

public: 
    using Shape::Shape;
};

class Goal : public Shape {
private:

public: 
    using Shape::Shape;
};

class SimWindow {
private:
    std::shared_ptr<sf::RenderWindow> window;
    std::string title;
    int x, y, width, height, framerate;
public:
    SimWindow(std::string title, int width, int height, int framerate) 
        : title(title), width(width), height(height), framerate(framerate) {}

    bool createWindow();
    void mainLoop(std::shared_ptr<Vehicle> vehicle, std::shared_ptr<Goal> goal);

    std::shared_ptr<sf::RenderWindow> getWindow() { return window; }
    int getX() { return x; }
    int getY() { return y; }
    int getWidth() { return width; }
    int getHeight() { return height; }
};

#endif