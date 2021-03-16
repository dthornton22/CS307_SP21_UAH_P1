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
		char inputFile[128];
		int clockMult{0};
		string inFile{"empty"};
		struct _timeb tStruct;
		double thisTime;
		double outputTime;

	public:
		Simulation(); 					// Default constructor
		~Simulation(); 					// Destructor
		double getFlightETA();			// Todo: what does this return
		void printReport();				// Prints report to terminal and output file
		void runSimulation();			// Runs the simulation
		void initializeSimulation();	// Set up the simulation

		// Set functions
		void setClockMult(int param);
		void setInFile(char param);

		// Get functions
		int getClockMult();
		string getInFile();
};

#endif




// The following needs to be in a loop. Use get functions to set the data inside the for loop. 
//printf("================================================================");
//printf("|  Flight Simulation - Status reports on all flights enroute.  |");
//printf("================================================================");
//printf("Current clock time: %d:^%d", CurrentHr, CurrentMin);
//printf("\n");
//printf("%s Flight %d - %s\n", Airline, FlightNum, Plane);
//printf("\tDeparts: %s (%f, %f) at %d:%d\n", DepSymbol, Lat, Lon, LocTimeHr, LocTimeMin); // char // double // double // int // int
//printf("\tArrives: %s (%f, %f) at %d:%d\n", DstSymbol, Lat, Lon, DstTimeHr, DstTimeMin); // char // double // double // int // int
//printf("\tCurrent location: (%f, %f)\n", CurrentLocLat, CurrentLocLon); // double // double
//printf("\t\t%f miles from %s, %f miles to %s", DepDistance, DepSymbol, DstDistance, DstSymbol); // double // char // double // char
//printf("\tCurrent Speed: %f MPH\n", CurrentSpeed);
//printf("\tCurrent Altitude: %f feet\n", CurrentAltitude);
//printf("================================================================");
//
//printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
//printf("Now arriving: %s Flight %d, %s", Airline, FlightNum, Plane);
//printf("\t\tAt %s, %s", DstCityName, DstStateName);
//printf("\t\tfrom %s, %s", DepCityName, DepCityName);
//printf("Current clock time: %d:%d", CurrentHr, CurrentMin);
//printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
//
//printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
//printf("Now departing: %s Flight %d, %s", Airline, FlightNum, Plane);
//printf("\t\tFrom %s, %s", DepCityName, DepStateName);
//printf("\t\tEn route to %s, %s", DstCityName, DstCityName);
//printf("\t\tEstimated Time of Arrival: %d:%d", )
//printf("Current clock time: %d:%d", CurrentHr, CurrentMin);
//printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

//printf("*** Starting simulation at %d:%d ***", CurrentHr, CurrentMin);
