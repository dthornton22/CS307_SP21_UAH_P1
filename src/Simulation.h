// ****************************************
// Program Title: Project1
// Project File: Simulation.h
// Name: David Thornton
// Course Section: CS-307, SP 2021
// Due Date: 03/14/2021
// ****************************************
#include <string>
#ifndef SIMULATION_H
#define SIMULATION_H

using namespace std;

class Simulation
{
	private:
		int clockMult{0};				// Speed of the program
		string inFile{"empty"};			// User provided input file

	public:
		Simulation(); 					// Default constructor
		~Simulation(); 					// Destructor
		int getFlightETA();				// Todo: what does this return
		void printReport();				// Prints report to terminal and output file
		void runSimulation();			// Runs the simulation
		void initializeSimulation();	// Set up the simulation

		// Set functions
		void setClockMult(int param);	// Sets the clockMult variable
		void setInFile(string param);	// Sets the inFile

		// Get functions
		int getClockMult();				// Gets the clockMult variable
		string getInFile();				// Gets the inFile variable
};

#endif
