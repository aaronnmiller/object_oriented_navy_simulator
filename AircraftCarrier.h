//Just creates an Aircraft Carrier derived from the Ship class. Adds aircraft that can be attached to it.

#pragma once

#include "Ship.h"

class AircraftCarrier : public Ship {
public:
  AircraftCarrier(std::string name, std::string id, int aircraft, int maxSpeed);

private:
  int aircraft;
};
