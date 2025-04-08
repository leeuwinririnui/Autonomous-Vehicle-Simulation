#ifndef VEHICLE_H
#define VEHICLE_H

#include "shape.h"
#include "goal.h"

class Goal;

class Vehicle : public Shape {
private:

public: 
    using Shape::Shape;

    void moveVehicle(std::shared_ptr<Goal> goal);
};

#endif