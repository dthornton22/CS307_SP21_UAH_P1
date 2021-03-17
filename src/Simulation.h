// ****************************************
// Program Title: Project1
// Project File: Simulation.h
// Name: David Thornton
// Course: CS-307
// Due Date: 03/16/2021
// ****************************************
#include "FlightDataParser.h"
#include "CityDataParser.h"
#include "CityData.h"
#include "FlightData.h"
#include "AircraftData.h"
#include <sys/types.h>	// needed for the _ftime_s() function
#include <sys/timeb.h>	// contains definition of _timeb struct
#include <time.h>		// needed for other time functions and structures
#include <string>
#ifndef SIMULATION_H
#define SIMULATION_H

using namespace std;

class Simulation
{
private:
	int clockMult{ 0 };
	int counter{ 0 };
	int CurrentMin{ 0 };
	int	CurrentHr{ 0 };
	string inputFile;
	struct _timeb tStruct { 0 };
	double thisTime{ 0 };
	double outputTime{ 0 };

	public:
		Simulation(); 					// Default constructor
		~Simulation(); 					// Destructor
		double getFlightETA();			// Todo: what does this return
		void printReport();				// Prints report to terminal and output file
		void runSimulation(double clocktime);// Runs the simulation
		void initializeSimulation();	// Set up the simulation
		void PrintCurrentTime();
		void PrintStartTime();
		City* testCity;// = new City(char(0), char(0), char(0), 0, 0);
		Flight* testFlight;// = new Flight(char(0), char(0), 0, char(0), 0, 0, char(0));
		Aircraft* testAircraft;// = new Aircraft(char(0), char(0), 0, 0, 0, 0, 0);

	// Set functions
	void setClockMult(int param);
	void setInFile(string param);

	// Get functions
	int getClockMult();
	string getInFile();
};

#endif
