// ****************************************
// Program Title: Programming Assignment 1
// Project File: Simulation.h
// Name: David Thornton
// Course: CS-307
// Due Date: 03/17/2021
// ****************************************
#include "CityData.h"
#include "FlightData.h"
#include "AircraftData.h"
#include "CityDataParser.h"
#include "FlightDataParser.h"
#include <time.h>
#include <string>
#include <sys/types.h>
#include <sys/timeb.h>
#ifndef SIMULATION_H
#define SIMULATION_H

using namespace std;

class Simulation
{
private:
	int clockMult{ 0 };
	int counter{ 0 };
	int curMin{ 0 };
	int	curHr{ 0 };
	string inputFile;
	struct _timeb tStruct { 0 };
	double thisTime{ 0 };
	double outputTime{ 0 };

public:
	Simulation();
	~Simulation();
	double getFlightETA(double distance, char* mak, vector<Aircraft> aircraft);
	void runSimulation(double clocktime);
	void setInFile(string param);
	void initializeSimulation();
	void printCurrentTime();
	void printStartTime();
	int getClockMult();
	string getInFile();
	City* myCity;
	Flight* myFlight;
	Aircraft* myAircraft;
};

#endif
