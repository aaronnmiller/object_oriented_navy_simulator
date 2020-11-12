#include "OrderAircraft.h"
#include "Aircraft.h"

DeployAircraft::DeployAircraft(ATime time, std::string id, int heading, int speed, int altitude)
: Order("DeployAircraftOrder", time, id), heading(heading), speed(speed), altitude(altitude) {}

void DeployAircraft::execute(Aircraft& aircraft) const {
    aircraft.takeoff(time, heading, speed, altitude);
}

LandAircraft::LandAircraft(ATime time, std::string aircraftID, Movable* ship)
: Order("LandAircraftOrder", time, aircraftID), ship(ship) {}

void LandAircraft::execute(Aircraft& aircraft) const {
    aircraft.land(ship);
}

ChangeAircraftOrders::ChangeAircraftOrders(ATime time, std::string id, int heading, int speed, int altitude)
: Order("ChangeAircraftOrder", time, id), heading(heading), speed(speed), altitude(altitude) {}

void ChangeAircraftOrders::execute(Aircraft& aircraft) const {
    aircraft.changeOrders(heading, speed, altitude);
}
