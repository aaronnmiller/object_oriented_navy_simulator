// This is the file that overall runs the simulation. Files are parsed, interpreted,
// and orders are created.

#pragma once

#include "ATime.h"
#include <queue>
#include <unordered_map>

class Movable;
class Order;

class PointerCompare {
public:
  template<typename T>
  bool operator()(T* left, T* right) {
    return *left > *right;
  }
};

typedef std::priority_queue<Order*, std::deque<Order*>, PointerCompare> Orders;
typedef std::unordered_map<std::string, Movable*> Navy;

class Simulation {
public:
  Simulation();
  ~Simulation();

  void execute(const std::string& input, const std::string& output);
  
private:
  void parse(const std::string& filename);
  void write(const std::string& filename);
  
  void set_start(std::istringstream& stream);
  void set_stop(std::istringstream& stream);
  void updatePositions();

  void createCruiser(std::istringstream& stream);
  void createAircraftCarrier(std::istringstream& stream);
  void createFighter(std::istringstream& stream);
  
  void deployShip(std::istringstream& stream);
  void deployAircraft(std::istringstream& stream);
  void landAircraft(std::istringstream& stream);
  void changeShipOrders(std::istringstream& stream);
  void changeAircraftOrders(std::istringstream& stream);
  
  ATime start, stop, current;
  Orders orders;
  Navy navy;
};
