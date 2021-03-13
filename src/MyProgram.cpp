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
    cout << "Starting program!!!\n\n";
    Simulation mySim; 	// Instantiate Simulation object

    // Test values
    mySim.setClockMult(1);
    mySim.setInFile("test");
    cout << "Clock mult: " << mySim.getClockMult() << endl;
    cout << "Infile: " << mySim.getInFile() << endl;

    // Call Simulation::initializeSimulation
    // Call Simulation::runSimulation
}
