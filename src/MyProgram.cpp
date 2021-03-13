// ****************************************
// Program Title: Project1
// Project File: MyProgram.cpp
// Name: David Thornton
// Course Section: CS-307, SP 2021
// Due Date: 03/14/2021
// ****************************************

#include "Simulation.h"
#include <iostream>

int main(int argc, char* argv[])
{
    cout << "Starting program!!!" << endl;
    Simulation mySim; 	            // Instantiate Simulation object
    mySim.initializeSimulation();   // Call Simulation::initializeSimulation
    mySim.runSimulation();          // Call Simulation::runSimulation
}
