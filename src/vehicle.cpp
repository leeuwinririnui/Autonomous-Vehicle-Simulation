#include "vehicle.h"

void Vehicle::moveVehicle(std::shared_ptr<Goal> goal) {
    sf::Vector2f vPos = getRect()->getPosition();
    sf::Vector2f gPos = goal->getRect()->getPosition();

    if (vPos != gPos) {
        if (vPos.x < gPos.x) vPos.x += 2;
        if (vPos.y < gPos.y) vPos.y += 2;
        if (vPos.x > gPos.x) vPos.x -= 2;
        if (vPos.y > gPos.y) vPos.y -= 2;

        getRect()->setPosition(vPos);
    }

}