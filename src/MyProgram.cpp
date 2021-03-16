// ****************************************
// Program Title: Project1
// Project File: MyProgram.cpp
// Name: David Thornton
// Course: CS-307
// Due Date: 03/16/2021
// ****************************************
#include "Simulation.h"
#include <iostream>

int main(int argc, char* argv[])
{
    Simulation mySim; 	            // Instantiate Simulation object
    mySim.initializeSimulation();   // Call Simulation::initializeSimulation
    mySim.runSimulation();          // Call Simulation::runSimulation
}
