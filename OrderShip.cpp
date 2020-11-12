#include "OrderShip.h"
#include "Ship.h"

DeployShip::DeployShip(ATime time, std::string id, int x, int y, int heading, int speed)
:Order("DeployShipOrder", time, id), x(x), y(y), heading(heading), speed(speed) {}

void DeployShip::execute(Ship& ship) const {
    ship.deploy(time, x, y, heading, speed);
}

ChangeShipOrders::ChangeShipOrders(ATime time, std::string id, int heading, int speed)
:Order("ChangeShipOrder", time, id), heading(heading), speed(speed) {}

void ChangeShipOrders::execute(Ship& ship) const {
    ship.changeOrders(heading, speed);
}
