// Functions that all orders share, OrderShip and OrderAircraft are derived classes.
// Main component are the virtual execute functions

#pragma once

#include "ATime.h"

class Ship;
class Aircraft;

class Order {
public:
  Order(std::string name, ATime time, std::string id);
  virtual ~Order() {}

  ATime getTime() const;
  std::string getID() const;
  
  // virtual functions that are run from either the OrderShip or OrderAircraft classes.
  // throws an error if the function is tried to run here
  virtual void execute(Ship& ship) const;
  virtual void execute(Aircraft& aircraft) const;

  friend bool operator>(const Order& left, const Order& right);
  friend std::ostream& operator<<(std::ostream& os, const Order& order);
  
protected:
  std::string name;
  ATime time;
  std::string id;
};

