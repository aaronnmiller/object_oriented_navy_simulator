// Derived from the Movable class. Adds the functionality necessary for something
// to be a ship.

#pragma once

#include "Movable.h"

class Ship : public Movable {
public:
  Ship(std::string name, std::string id, int maxSpeed);

  void deploy(ATime t, int x, int y, int heading, int speed);
  void changeOrders(int heading, int speed);
  virtual void accept(const Order& order);
  virtual void updatePosition(ATime t);
};
