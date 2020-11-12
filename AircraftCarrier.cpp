#include "AircraftCarrier.h"

AircraftCarrier::AircraftCarrier(std::string name, std::string id, int aircraft, int maxSpeed)
:Ship(name, id, maxSpeed), aircraft(aircraft) {
    className = "Aircraft Carrier";
    position = Vector3D(0, 0, 0);
}
