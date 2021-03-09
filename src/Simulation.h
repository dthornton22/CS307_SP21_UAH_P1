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
		int clockMult;		// Speed of the program
		string infile;		// User provided input file

	public:
		Simulation(); 		// Default constructor
		~Simulation(); 		// Destructor
		int getFlightETA();	// 
		void printReport();	// Prints report to terminal and output file
};

#endif
