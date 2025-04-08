#include "init.h"

void initializeSimulation(
    std::shared_ptr<SimWindow>& window,
    std::shared_ptr<Vehicle>& vehicle,
    std::shared_ptr<Goal>& goal,
    std::shared_ptr<sf::Vector2f>& boundaries
) {
    window = std::make_shared<SimWindow>(
        "Autonomous Vehicle Simulation", 800, 600, 60
    );

    sf::Vector2f vPos(0.f, window->getHeight() / 4);
    sf::Vector2f gPos(window->getWidth() - 30, window->getHeight() / 2);

    vehicle = std::make_shared<Vehicle>(
        "Vehicle", vPos, 30, 15, 200, 30, 45
    );

    goal = std::make_shared<Goal>(
        "Goal", gPos, 30, 15, 255, 255, 255  
    );

    boundaries = std::make_shared<sf::Vector2f>(800, 600);
}