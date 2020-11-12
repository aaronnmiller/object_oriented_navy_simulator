#Navy Simulator

This program simulates the movement of a navy in a battle-like setting. Ships and aircraft can move freely on either two or three axes (depending on the craft).

##The necessary format of the orders in the file:
StartSim mm/dd/yyyy hh:mm:ss
StopSim mm/dd/yyyy hh:mm:ss

CreateCuiser name id numberOfMissiles maxSpeed
CreateAircraftCarrier name id numberOfAircraft maxSpeed
CreateFighter name id shipID maxSpeed maxAltitude numberOfBombs

DeployShip mm/dd/yyyy hh:mm:ss id xPosition yPosition headingDegrees speed
DeployAircraft mm/dd/yyyy hh:mm:ss id headingDegrees speed altitude

LandAircraft mm/dd/yyyy hh:mm:ss shipID id

ChangeShipOrders mm/dd/yyyy hh:mm:ss id headingDegrees speed
ChangeAircraftOrders mm/dd/yyyy hh:mm:ss id headingDegrees speed altitude

Comments in the orders file can be made with # at the beginning of the line

##Running the program
There are two arguments when running the file: inputFile and outputFile

Output file is in a .json format and gives the x, y, z coordinates as a function of time for each movable throughout the simulation. A location is recorded every minute.