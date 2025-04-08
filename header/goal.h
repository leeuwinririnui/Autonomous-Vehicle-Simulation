#ifndef GOAL_H
#define GOAL_H

#include "shape.h"
#include "vehicle.h"

class Vehicle;

class Goal : public Shape {
private:
    sf::Vector2f destination;
    bool isMoving = false;
    bool isParked = false;
public: 
    Goal(
        std::string name, 
        sf::Vector2f pos, 
        float width, 
        float height, 
        int red, 
        int green, 
        int blue
    );

    void setDestination(std::shared_ptr<sf::Vector2f>& boundaries);
    void moveGoal(std::shared_ptr<sf::Vector2f>& boundaries);
    void checkParked(std::shared_ptr<Vehicle>& vehicle);

    void setMoving(bool isMoving);

    sf::Vector2f getDestination();
    bool getMoving();
    bool getParked();
};

#endif