#ifndef INIT_H
#define INIT_H

#include "window.h"
#include "shape.h"
#include "vehicle.h"
#include "goal.h"

void initializeSimulation(
    std::shared_ptr<SimWindow>& window,
    std::shared_ptr<Vehicle>& vehicle,
    std::shared_ptr<Goal>& goal,
    std::shared_ptr<sf::Vector2f>& boundaries
);

#endif