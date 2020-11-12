#include "Aircraft.h"

Aircraft::Aircraft(std::string name, std::string id, Movable* ship, int maxSpeed, int maxAltitude)
  :Movable(name, id, maxSpeed), ship(ship), maxAltitude(maxAltitude) {
  className = "Aircraft";
}

void Aircraft::takeoff(ATime t, int newHeading, int newSpeed, int newAltitude) {
    deployed = true;
    time = t;
    ship = nullptr;
    history.push_back(std::pair<ATime, Vector3D> (t, position));
    setVelocity(newHeading, newSpeed);
    if (newAltitude <= maxAltitude) {
        position.z = (newAltitude/5280.0);
    } else {
        position.z = (maxAltitude/5280.0);
    }
}

// does not actually land the aircraft, just "attaches" a plane to a ship,
// updatePosition is then called until it lands
void Aircraft::land(Movable* newShip) {
    ship = newShip;
}

// -1 is used for newAltitude if the altitude is not supposed to change
void Aircraft::changeOrders(int newHeading, int newSpeed, int newAltitude) {
    setVelocity(newHeading, newSpeed);
    if (newAltitude == -1) {}
    else if (newAltitude <= maxAltitude) {
        position.z = newAltitude;
    }
    else {
        position.z = maxAltitude;
    }
}

// intermediate step for accepting orders, used so the right execute function is
// called based on the object passed to it
void Aircraft::accept(const Order& order) {
  order.execute(*this);
}

void Aircraft::updatePosition(ATime t) {
    if (deployed) {
        //if not "attached" to a ship, fly in a straight line
        if (ship == nullptr) {
            position += velocity * ((t - time)/3600.0);
            time = t;
            history.push_back(std::pair<ATime, Vector3D> (t, position));
        }
        // if "attached" to a ship, fly towards it until close enough to land
        else {
            Vector3D diffVector = (ship -> getPosition() - position);
            if (diffVector.norm() > (diffVector.unit() * speed * ((t-time)/3600.0)).norm()) {
                position += diffVector.unit() * speed * ((t-time)/3600.0);
                time = t;
                history.push_back(std::pair<ATime, Vector3D> (t, position));
            } else {
                position = ship -> getPosition();
                history.push_back(std::pair<ATime, Vector3D> (t, position));
                deployed = false;
            }
        }
    }
    // if not deployed...
    else {
        position = ship->getPosition();
    }
}

