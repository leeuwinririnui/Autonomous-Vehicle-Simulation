#include "init.h"

int main() {
    std::shared_ptr<SimWindow> window;
    std::shared_ptr<Vehicle> vehicle;
    std::shared_ptr<Goal> goal;
    std::shared_ptr<sf::Vector2f> boundaries;

    initializeSimulation(window, vehicle, goal, boundaries);

    window->createWindow();
    window->mainLoop(vehicle, goal, boundaries);

    std::string confirm;
    std::cout << "Confirm Exit: ";
    getline(std::cin, confirm);

    return 0;
}
