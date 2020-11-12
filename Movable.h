// This is the base class for anything that moves in the simulation.
// Except for setVelocity and simple return functions, most functionality
// is stored in the derived classes.

#pragma once

#include "Vector3D.h"
#include "ATime.h"
#include "Order.h"
#include <vector>

typedef std::pair<ATime, Vector3D> Location;
typedef std::vector<Location> LocationHistory;

class Movable {
public:
  Movable(std::string name, std::string id, int maxSpeed);
  virtual ~Movable() {}

  std::string getClassName() const;
  std::string getName() const;
  std::string getID() const;
  bool isDeployed() const;
  Vector3D getPosition() const;
  const LocationHistory& getHistory() const;

  virtual void accept(const Order& order) = 0;
  virtual void updatePosition(ATime t) = 0;

  friend std::ostream& operator<<(std::ostream& os, const Movable& movable);
  
protected:
  std::string className, name, id;
  bool deployed;
  int heading, speed, maxSpeed;
  Vector3D position, velocity;
  ATime time;
  LocationHistory history;
  void setVelocity(int heading, int speed);
};

