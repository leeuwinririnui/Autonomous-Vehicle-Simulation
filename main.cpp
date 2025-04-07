#include "window.cpp"

int main() {
    std::shared_ptr<SimWindow> window = std::make_shared<SimWindow>(
        "Autonomous Vehicle Simulation", 
        800, 
        600,
        60
    );

    std::shared_ptr<Vehicle> vehicle = std::make_shared<Vehicle>(
        "Vehicle",
        0,
        window->getHeight() / 2,
        30,
        15,
        200, 
        30, 
        45
    );

    std::shared_ptr<Goal> goal = std::make_shared<Goal>(
        "Goal",
        window->getWidth() - 30,
        window->getHeight() / 2,
        30,
        15,
        255, 
        255, 
        255  
    );

    window->createWindow();
    window->mainLoop(vehicle, goal);

    return 0;
}