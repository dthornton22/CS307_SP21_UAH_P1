// ****************************************
// Program Title: Programming Assignment 1
// Project File: Simulation.h
// Name: David Thornton
// Course: CS-307
// Due Date: 03/17/2021
// ****************************************
#include "FlightDataParser.h"
#include "CityDataParser.h"
#include "CityData.h"
#include "FlightData.h"
#include "AircraftData.h"
#include <sys/types.h>
#include <sys/timeb.h>
#include <time.h>
#include <string>
#ifndef SIMULATION_H
#define SIMULATION_H

using namespace std;

class Simulation
{
private:
	int clockMult{ 0 };
	int Counter{ 0 };
	int CurrentMin{ 0 };
	int	CurrentHr{ 0 };
	string inputFile;
	struct _timeb tStruct { 0 };
	double thisTime{ 0 };
	double outputTime{ 0 };

public:
	Simulation();
	~Simulation();
	double getFlightETA(double distance, char* mak, vector<Aircraft> aircraft);
	void runSimulation(double clocktime);
	void initializeSimulation();
	void PrintCurrentTime();
	void PrintStartTime();

	City* testCity;
	Flight* testFlight;
	Aircraft* testAircraft;

	// Set functions
	void setInFile(string param);

	// Get functions
	int getClockMult();
	string getInFile();
};

#endif
