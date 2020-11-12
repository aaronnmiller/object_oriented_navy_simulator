#include "Ship.h"

Ship::Ship(std::string name, std::string id, int maxSpeed)
  :Movable(name, id, maxSpeed) {
  className = "Ship";
}

void Ship::deploy(ATime t, int x, int y, int newHeading, int newSpeed) {
    deployed = true;
    time = t;
    position.x = x;
    position.y = y;
    setVelocity(newHeading, newSpeed);
    history.push_back(std::pair<ATime, Vector3D> (t, position));
}

void Ship::changeOrders(int newHeading, int newSpeed) {
    setVelocity(newHeading, newSpeed);
}

// intermediate step for accepting orders, used so the right execute function is
// called based on the object passed to it
void Ship::accept(const Order& order) {
  order.execute(*this);
}

// ship travels in just a straight line whenever deployed
void Ship::updatePosition(ATime t) {
    if (deployed) {
        position += velocity * ((t-time)/3600.0);
        history.push_back(std::pair<ATime, Vector3D> (t, position));
        time = t;
    }
}

