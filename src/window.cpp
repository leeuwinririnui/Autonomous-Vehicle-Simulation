#include "window.h"
#include "shape.h"

SimWindow::SimWindow(std::string title, int width, int height, int framerate) 
    : title(title), width(width), height(height), framerate(framerate) {}

bool SimWindow::createWindow() {
    window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(width, height), 
        title
    );

    if (!window) {
        std::cerr << "Error creating SFML Window!" << std::endl;
        return false;
    }

    window->setFramerateLimit(framerate);

    std::unique_ptr<sf::VideoMode> desktop = std::make_unique<sf::VideoMode>(
        sf::VideoMode::getDesktopMode()
    );

    x = (desktop->width - width) / 2;
    y = (desktop->height - height) / 2;

    window->setPosition(sf::Vector2i(x, y));

    return true;
}

void SimWindow::mainLoop(
    std::shared_ptr<Vehicle>& vehicle, 
    std::shared_ptr<Goal>& goal,
    std::shared_ptr<sf::Vector2f>& boundaries
) {
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        goal->checkParked(vehicle);
        vehicle->moveVehicle(goal);
        if (!goal->getParked()) {
            if (!goal->getMoving()) {
                goal->setDestination(boundaries);
            } else {
                goal->moveGoal(boundaries);
            }
        }

        window->clear(sf::Color::Black);
        goal->draw(window);
        vehicle->draw(window);
        window->display();
    }
}

std::shared_ptr<sf::RenderWindow> SimWindow::getWindow() { return window; }
int SimWindow::getX() { return x; }
int SimWindow::getY() { return y; }
int SimWindow::getWidth() { return width; }
int SimWindow::getHeight() { return height; }