// Derived class from Orders for functionality specific to ships.
// Both creates new ship orders and executes the function necessary when
// execute is called from the ship (or derived) class

#pragma once

#include "Order.h"
#include "ATime.h"

class Ship;

class DeployShip : public Order {
public:
  DeployShip(ATime time, std::string id, int x, int y, int heading, int speed);
  void execute(Ship& ship) const override;
  
private:
  int x, y, heading, speed;
};

class ChangeShipOrders : public Order {
public:
  ChangeShipOrders(ATime time, std::string id, int heading, int speed);
  void execute(Ship& ship) const override;

private:
  int heading, speed;
};
