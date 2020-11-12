// Derived class from Orders for functionality specific for aircraft.
// Both creates new aircraft orders and executes the function necessary when
// execute is called from the aircraft (or derived) class

#pragma once

#include "Order.h"
#include "ATime.h"

class Movable;
class Aircraft;

class DeployAircraft : public Order {
public:
  DeployAircraft(ATime time, std::string id, int heading, int speed, int altitude);
  void execute(Aircraft& aircraft) const override;
  
private:
  int heading, speed, altitude;
};


class LandAircraft : public Order {
public:
  LandAircraft(ATime time, std::string aircraftID, Movable* ship);
  void execute(Aircraft& aircraft) const override;
  
private:
  Movable* ship;
};


class ChangeAircraftOrders : public Order {
public:
  ChangeAircraftOrders(ATime time, std::string id, int heading, int speed, int altitude);
  void execute(Aircraft& aircraft) const override;

private:
  int heading, speed, altitude;
};

