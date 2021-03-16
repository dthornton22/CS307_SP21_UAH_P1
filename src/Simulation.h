// ****************************************
// Program Title: Project1
// Project File: Simulation.h
// Name: David Thornton
// Course Section: CS-307, SP 2021
// Due Date: 03/14/2021
// ****************************************
#include "FlightDataParser.h"
#include "CityDataParser.h"
#include "CityData.h"
#include "FlightData.h"
#include "AircraftData.h"
#include <sys/types.h>     // needed for the _ftime_s() function
#include <sys/timeb.h>     // contains definition of _timeb struct
#include <time.h>          // needed for other time functions and structures
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
		struct _timeb   tStruct;
		double          thisTime;
		double          outputTime;
		int				CurrentMin;
		int				CurrentHr;
		bool            done = false;  // while loop flag

	public:
		Simulation(); 					// Default constructor
		~Simulation(); 					// Destructor
		double getFlightETA();			// Todo: what does this return
		void printReport();				// Prints report to terminal and output file
		void runSimulation(double clocktime);// Runs the simulation
		void initializeSimulation();	// Set up the simulation


		// Set functions
		void setClockMult(int param);
		void setInFile(char param);
		City *testCity;// = new City(char(0), char(0), char(0), 0, 0);
		Flight *testFlight;// = new Flight(char(0), char(0), 0, char(0), 0, 0, char(0));
		Aircraft *testAircraft;// = new Aircraft(char(0), char(0), 0, 0, 0, 0, 0);

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
//printf("        Departs: %s (%f, %f) at %d:%d\n", DepSymbol, Lat, Lon, LocTimeHr, LocTimeMin); // char // double // double // int // int
//printf("        Arrives: %s (%f, %f) at %d:%d\n", DstSymbol, Lat, Lon, DstTimeHr, DstTimeMin); // char // double // double // int // int
//printf("        Current location: (%f, %f)\n", CurrentLocLat, CurrentLocLon); // double // double
//printf("                  %f miles from %s, %f miles to %s", DepDistance, DepSymbol, DstDistance, DstSymbol); // double // char // double // char
//printf("        Current Speed: %f MPH\n", CurrentSpeed);
//printf("        Current Altitude: %f feet\n", CurrentAltitude);
//printf("================================================================");
//

//


//printf("*** Starting simulation at %d:%d ***", CurrentHr, CurrentMin);