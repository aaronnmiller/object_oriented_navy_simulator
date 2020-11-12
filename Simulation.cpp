#include "Simulation.h"

#include "Movable.h"
#include "Order.h"
#include "OrderShip.h"
#include "OrderAircraft.h"
#include "AircraftCarrier.h"
#include "Cruiser.h"
#include "Fighter.h"
#include "Output.h"

#include <fstream>
#include <sstream>

Simulation::Simulation() {}

// after the simulation has been run, deletes any remaining
// movables in the navy or orders
Simulation::~Simulation() {
  for (auto [id, movable] : navy) {
    delete movable;
  }
  while (!orders.empty()) {
    delete orders.top();
    orders.pop();
  }
}

// execute is called by main, starts the program
void Simulation::execute(const std::string& input, const std::string& output) {
    parse(input);
    current = start; //current time
    
  while (!orders.empty()) {
      Order* order = orders.top();
      
    while (current < order->getTime()) { //move time forward until the time of the next order
        current += 60;
        updatePositions();
    }
      
      std::string orderID = order->getID();
      if (navy.find(orderID) != navy.end()) { //if not found in the navy
          navy[orderID]->accept(*order);
      }
      else {
          std::cout << "ID " << orderID << "not found in Navy" << std::endl;
      }
      
      delete orders.top();
      orders.pop();
  }
    
    // run time until the end of the simulation
  while (current < stop) {
      current += 60;
      updatePositions();
  }
  write(output);
}

// Parses the input file and creates orders for each line.
// Creates an order by passing the rest of the line in a stream.
void Simulation::parse(const std::string& filename) {
    
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Invalid filename: " + filename);
    }
    
    std::string str;
    while (std::getline(file, str)) {
        if (str.empty()) {
            continue;
        }
        std::istringstream stream(str);
        std::string opcode;
        stream >> opcode;
        
        if (opcode == "StartSim") {
            set_start(stream);
        }
        else if (opcode == "StopSim") {
            set_stop(stream);
        }
        else if (opcode == "CreateCruiser") {
            createCruiser(stream);
        }
        else if (opcode == "CreateAircraftCarrier") {
            createAircraftCarrier(stream);
        }
        else if (opcode == "CreateFighter") {
            createFighter(stream);
        }
        else if (opcode == "DeployShip") {
            deployShip(stream);
        }
        else if (opcode == "DeployAircraft") {
            deployAircraft(stream);
        }
        else if (opcode == "LandAircraft") {
            landAircraft(stream);
        }
        else if (opcode == "ChangeShipOrders") {
            changeShipOrders(stream);
        }
        else if (opcode == "ChangeAircraftOrders") {
            changeAircraftOrders(stream);
        }
        else if (opcode.empty()) {
            continue;
        }
        else if (opcode.at(0) == '#') { //if the line is a comment
            continue;
        }
        else {
            throw std::runtime_error("Invalid opcode: " + opcode);
        }
    }
}

// writes the data in the location history vector to a .json format
void Simulation::write(const std::string& filename) {
  std::ofstream output(filename);
  output << "{" << std::endl;
  size_t counter = 0;
  size_t N = navy.size()-1;
  for (auto [id, movable] : navy) {
    output << "  " << quote(id) << ": {" << std::endl;
    std::vector<int> time;
    std::vector<double> x, y, z;
    for (auto [t, position] : movable->getHistory()) {
      int elapsedMinutes = (t - start) / 60;
      time.push_back(elapsedMinutes);
      x.push_back(position.x);
      y.push_back(position.y);
      z.push_back(position.z);
    }
    output << "    " << keyvalue("t", time) << "," << std::endl;
    output << "    " << keyvalue("x", x) << "," << std::endl;
    output << "    " << keyvalue("y", y) << "," << std::endl;
    output << "    " << keyvalue("z", z) << std::endl;
    output << "  }";
    if (counter < N) output << ",";
    output << std::endl;
    counter++;
  }
  output << "}" << std::endl;
}

void Simulation::set_start(std::istringstream& stream) {
    std::string date, time;
    stream >> date >> time;
    start = ATime(date, time);
}

void Simulation::set_stop(std::istringstream& stream) {
    std::string date, time;
    stream >> date >> time;
    stop = ATime(date, time);
}

void Simulation::updatePositions() {
  for (auto [id, movable] : navy) {
    movable->updatePosition(current);
  }
}

void Simulation::createCruiser(std::istringstream& stream) {
    std::string name, id;
    int missiles, maxSpeed;
    stream >> name >> id >> missiles >> maxSpeed;
    navy[id] = new Cruiser(name, id, missiles, maxSpeed);
}

void Simulation::createAircraftCarrier(std::istringstream& stream) {
    std::string name, id;
    int aircraft, maxSpeed;
    stream >> name >> id >> aircraft >> maxSpeed;
    navy[id] = new AircraftCarrier(name, id, aircraft, maxSpeed);
}

void Simulation::createFighter(std::istringstream& stream) {
    std::string name, id, shipID;
    int maxSpeed, maxAltitude, bombs;
    
    stream >> name >> id >> shipID >> maxSpeed >> maxAltitude >> bombs;
    if (navy.find(shipID) != navy.end()) {
        Movable* ship = navy[shipID];
        navy[id] = new Fighter(name, id, ship, maxSpeed, maxAltitude, bombs);
    } else {
        std::cout << "Ship " << shipID << " not found in navy" << std::endl;
    }
    
}

void Simulation::deployShip(std::istringstream& stream) {
    std::string date, time, id;
    int x, y, heading, speed;
    stream >> date >> time >> id >> x >> y >> heading >> speed;
    ATime t(date, time);
    Order* order = new DeployShip(t, id, x, y, heading, speed);
    orders.push(order);
}

void Simulation::deployAircraft(std::istringstream& stream) {
    std::string date, time, id;
    int heading, speed, altitude;
    stream >> date >> time >> id >> heading >> speed >> altitude;
    ATime t(date, time);
    Order* order = new DeployAircraft(t, id, heading, speed, altitude);
    orders.push(order);
}

void Simulation::landAircraft(std::istringstream& stream) {
    std::string date, time, name, id, shipID;
    stream >> date >> time >> shipID >> id;
    if (navy.find(shipID) != navy.end()) {
        Movable* ship = navy[shipID];
        ATime t(date, time);
        Order* order = new LandAircraft(t, id, ship);
        orders.push(order);
    } else {
        std::cout << "Ship " << shipID << " not found in navy" << std::endl;
    }
}

void Simulation::changeShipOrders(std::istringstream& stream) {
    std::string date, time, id;
    int heading, speed;
    stream >> date >> time >> id >> heading >> speed;
    ATime t(date, time);
    Order* order = new ChangeShipOrders(t, id, heading, speed);
    orders.push(order);
}

void Simulation::changeAircraftOrders(std::istringstream& stream) {
    std::string date, time, id;
    int heading, speed, altitude;
    stream >> date >> time >> id >> heading >> speed >> altitude;
    ATime t(date, time);
    Order* order = new ChangeAircraftOrders(t, id, heading, speed, altitude);
    orders.push(order);
}
