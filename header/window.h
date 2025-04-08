#ifndef WINDOW_H
#define WINDOW_H

#include <memory>
#include <SFML/Graphics.hpp>

#include "vehicle.h"

class SimWindow {
private:
    std::shared_ptr<sf::RenderWindow> window;
    std::string title;
    int x, y, width, height, framerate;
public:
    SimWindow(std::string title, int width, int height, int framerate);

    bool createWindow();
    void mainLoop(
        std::shared_ptr<Vehicle>& vehicle, 
        std::shared_ptr<Goal>& goal, 
        std::shared_ptr<sf::Vector2f>& boundaries
    );

    std::shared_ptr<sf::RenderWindow> getWindow();
    int getX();
    int getY();
    int getWidth();
    int getHeight();
};

#endif