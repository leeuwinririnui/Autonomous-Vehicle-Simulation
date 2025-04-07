#include "core.h"
#include "shape.cpp"

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

void SimWindow::mainLoop(std::shared_ptr<Vehicle> vehicle, std::shared_ptr<Goal> goal) {
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) window->close();
        }

        sf::Vector2f vPos = vehicle->getRect()->getPosition();
        sf::Vector2f gPos = goal->getRect()->getPosition();

        if (vPos.x < gPos.x) {
            vehicle->getRect()->setPosition(vPos.x + 2, vPos.y);
        }

        if (vPos.y < gPos.y) {
            vehicle->getRect()->setPosition(vPos.x, vPos.y + 2);
        }

        window->clear(sf::Color::Black);
        goal->draw(window);
        vehicle->draw(window);
        window->display();
    }
}