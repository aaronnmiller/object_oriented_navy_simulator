// Test code for Order functionality
/*
#include <iostream>
#include "Order.h"
#include "Ship.h"
#include "Aircraft.h"
#include "Movable.h"
#include "OrderAircraft.h"
#include "OrderShip.h"

using namespace std;

int main() {
    
    Ship testShip("testShip", "A1", 60);
    Aircraft testAircraft("testAircraft", "A2", &testShip, 600, 30000);
    
    cout << testShip << endl;
    cout << testAircraft << endl;
    
    ATime time("4/20/2020", "16:20:00");
    
    DeployAircraft test1(time, "A1", 30, 540, 20000);
    DeployShip test2(time, "A2", 0, 0, 45, 35);
    
    ChangeShipOrders test3(time, "A2", 240, 15);
    ChangeAircraftOrders test4(time, "A1", 180, 300, 15000);
    
    LandAircraft test5(time, "A2", &testShip);
    
    cout << test1 << endl;
    cout << test2 << endl << endl;
    
    testAircraft.accept(test1);
    testShip.accept(test2);
    
    cout << testAircraft << endl;
    cout << testShip << endl;
    
    testAircraft.accept(test4);
    testShip.accept(test3);
    
    cout << testAircraft << endl;
    cout << testShip << endl;
    
    testAircraft.accept(test5);
    
    cout << testAircraft << endl;
    
    try {
        testAircraft.accept(test2);
    }
    catch (invalid_argument e) {
        cout << e.what() << endl;
    }
    
    try {
        testShip.accept(test1);
    }
    catch (invalid_argument e) {
        cout << e.what() << endl;
    }
    
    return 0;
}
*/
