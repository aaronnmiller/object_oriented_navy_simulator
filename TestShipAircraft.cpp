// Test code for ship and aircraft functionality

/*
#include "AircraftCarrier.h"
#include "Fighter.h"
#include "ATime.h"

#include <iostream>

using namespace std;

int main() {
  // Write some test code to verify that Ships and Aircraft move
  // correctly.  Your test code can be performed using the abstract
  // types Ship/Aircraft or with the concrete types Carrier and
  // Fighter.
  
  // This is a core part of the simulation! Make sure that your
  // updatePosition() functions properly. Any bugs that you miss
  // detecting at this checkpoint will only become harder to track
  // down later, as we add more functionality to a project.  My advice
  // is to write many tests and check that each member function of
  // Ship and Aircraft does what you expect it to.

  // Here is a test example to get you started. If you choose speeds
  // in multiples of 60 mph and tick the clock forward by one minute,
  // then positions will be nearly integer values (easier to reason
  // about, in my opinion).

  // Create our movable objects
  AircraftCarrier carrier("USS_Texas", "CGN-39", 1, 60);
  Fighter jet("F22 Raptor", "F22", &carrier, 600, 30000, 0);
    
    //cout << carrier << endl;
    //cout << jet << endl;

  // Set the start time
  ATime time("4/2/2020", "10:00:00");

  // Deploy both now
  carrier.deploy(time, 0, 0, 0, 60);
  jet.takeoff(time, 90, 600, 10000);
    
    cout << carrier << endl;
    cout << jet << endl;

  // Move foward in time for 5 minutes
  for (int i = 0; i < 5; i++) {
    time += 60; // add one minute
    carrier.updatePosition(time);
    jet.updatePosition(time);
  }

  // At 10:05, change the Carrier heading and tell the jet to land
  carrier.changeOrders(90, 30);
  jet.land(&carrier);

  // Move forward in time 5 minutes. During this time the jet will
  // land at 10:10 when it is close enough to the Carrier (note in the
  // output that Jet and Carrier's position coincide at 10:10,
  // indicating that it landed).
  for (int i = 0; i < 10; i++) {
    time += 60; // add one minute
    carrier.updatePosition(time);
    jet.updatePosition(time);
  }
    
    jet.takeoff(time, 230, 550, 25000);
    
    for (int i = 0; i < 10; i++) {
      time += 60; // add one minute
      carrier.updatePosition(time);
      jet.updatePosition(time);
    }
    
    std::cout << "Carrier's position history" << std::endl;
    for (auto loc : carrier.getHistory()) {
      std::cout << loc.first << ": " << loc.second << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Jet's position history" << std::endl;
    for (auto loc : jet.getHistory()) {
      std::cout << loc.first << ": " << loc.second << std::endl;
    }
}
*/
