#include "goal.h"

Goal::Goal(
    std::string name, 
    sf::Vector2f pos, 
    float width, 
    float height, 
    int red, 
    int green, 
    int blue
) : Shape(name, pos, width, height, red, green, blue), destination(0, 0) {
    srand(time(NULL));
}


void Goal::setDestination(std::shared_ptr<sf::Vector2f>& boundaries) {
    destination.y = rand() % (int)(boundaries->y);

    isMoving = true;
}

void Goal::moveGoal(std::shared_ptr<sf::Vector2f>& boundaries) {
    sf::Vector2f gPos = getRect()->getPosition();

    if (std::abs(gPos.y - destination.y) > 5.0f) {
        if (gPos.y < destination.y) gPos.y += 2;
        if (gPos.y > destination.y) gPos.y -= 2;

        getRect()->setPosition(gPos);
    } else {
        isMoving = false;
    }

}

void Goal::checkParked(std::shared_ptr<Vehicle>& vehicle) {
    const sf::Vector2f vPos = vehicle->getRect()->getPosition();
    const sf::Vector2f gPos = getRect()->getPosition();

    const float tolerance = 3.0f;
    const bool withinX = std::abs(vPos.x - gPos.x) <= tolerance;
    const bool withinY = std::abs(vPos.y - gPos.y) <= tolerance;

    isParked = (withinX && withinY);

    if (isParked) std::cout << "Vehicle is parked" << std::endl;

}

void Goal::setMoving(bool moving) { this->isMoving = moving; }

sf::Vector2f Goal::getDestination() { return destination; }
bool Goal::getMoving() { return isMoving; }
bool Goal::getParked() { return isParked; }
