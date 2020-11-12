#include "Order.h"

using namespace std;

Order::Order(string name, ATime time, string id)
:name(name), time(time), id(id) {}

ATime Order::getTime() const {
    return time;
}

string Order::getID() const {
    return id;
}

// If neither the OrderShip or OrderAircarft execute functions are able
// to execute, these funtions are called to throw an error
void Order::execute(Ship& ship) const {
    throw invalid_argument("Cannot execute " + name + " on Ship");
}

void Order::execute(Aircraft& aircraft) const {
    throw invalid_argument("Cannot execute " + name + " on Aircraft");
}

bool operator>(const Order& left, const Order& right) {
    return left.time > right.time;
}

// Mostly for tetsing, just prints out the order in a nice format
ostream& operator<<(std::ostream& os, const Order& order) {
    os << order.time << ", " << order.id << ", " << order.name;
    return os;
}
