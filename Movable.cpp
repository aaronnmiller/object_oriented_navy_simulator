#include "Movable.h"
#include <cmath>
#include <iostream>


Movable::Movable(std::string name, std::string id, int maxSpeed)
  :className("Movable"), name(name), id(id), deployed(false),
   heading(0), speed(0), maxSpeed(maxSpeed) {}

std::string Movable::getClassName() const {
    return className;
}

std::string Movable::getName() const {
    return name;
}

std::string Movable::getID() const {
    return id;
}

bool Movable::isDeployed() const {
    return deployed;
}

Vector3D Movable::getPosition() const {
    return position;
}

const LocationHistory& Movable::getHistory() const {
    return history;
}

// if either argument is -1, the value for the object does not change
// if newSpeed is greater than maxSpeed, maxSpeed is used for the new value
// newHeading is in degrees, with N = 0, E = 90, S = 180, W = 270
void Movable::setVelocity(int newHeading, int newSpeed) {

    if (newSpeed > maxSpeed) {
        newSpeed = maxSpeed;
    }
    
    if (newSpeed != -1) {
        speed = newSpeed;
    }
    if (newHeading != -1) {
        heading = newHeading;
    }
    
    // heading converted to the unit circle to make math easier
    int degrees = (360 - (heading - 90)) % 360;
    double radians = degrees * (M_PI / 180);
    double vx = cos(radians) * speed;
    double vy = sin(radians) * speed;

    velocity = Vector3D(vx, vy, 0);
}

// just outputs info on a generic movable in a nice format, mostly for testing purposes
std::ostream& operator<<(std::ostream& os, const Movable& m) {
    os << m.getClassName() << " (" << m.getID() << " / " << m.getName() << ")" << std::endl
    << "Depolyed: " << std::boolalpha << m.isDeployed() << std::endl
    << "Heading: " << m.heading << ", Speed: " << m.speed << " (max speed: " << m.maxSpeed << ")" << std::endl
    << "Velocity: " << m.velocity << std::endl
    << "Position: " << m.getPosition()
    << std::endl;
  return os;
}
