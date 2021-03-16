// ****************************************
// Program Title: Project1
// Project File: Simulation.cpp
// Name: David Thornton
// Course: CS-307
// Due Date: 03/16/2021
// ****************************************
#include "Simulation.h"

Simulation::Simulation()
{
	printf("==============================================================\n");
	printf("|          AIRLINE FLIGHT SIMULATION DEMONSTRATION           |\n");
	printf("|            CS 307 -- Programming Assignment 1              |\n");
	printf("==============================================================\n");
	printf("\nPlease enter the name of the simulation data file then press Enter:\n");
	cin >> inputFile;

	printf("\nAt what speed do you want to run the simulation? (1x, 2x, 3x)\n");
	printf("        Please enter 1, 2, or 3 and press Enter.\n");
	cin >> clockMult;

	City *testCity = new City(char(0), char(0), char(0), 0, 0);
	testCity->readData();
	Flight *testFlight = new Flight(char(0), char(0), 0, char(0), 0, 0, char(0));
	testFlight->readData();
	Aircraft *testAircraft = new Aircraft(char(0), char(0), 0, 0, 0, 0, 0);
	testAircraft->readData();
	runSimulation();
}

Simulation::~Simulation()
{
	
}

double Simulation::getFlightETA()
{
	return 0;
}

void Simulation::printReport()
{
	cout << "Yo what's up this is ez pz" << endl;
}

void Simulation::runSimulation()
{
	_ftime_s(&tStruct);	// Get start time
	thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
	outputTime = thisTime + 1.0; // Set next 1 second interval time (we could add, e.g., .5 to delay just a half second)
	bool done = false; // while loop flag
	while (!done)     // Start an eternal loop
	{
		_ftime_s(&tStruct);    // Get the current time
		thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
		// Check for 1 second interval to print status to screen
		if (thisTime >= outputTime)
		{
			printReport();     // Call function to print all data
			outputTime += 1.0; // Set time for next 1 second interval
		}
		// Do other stuff here
	}
}

void Simulation::initializeSimulation()
{

}

void Simulation::setClockMult(int param)
{
	this->clockMult = param;
}

void Simulation::setInFile(char param)
{
	this->inFile = param;
}

int Simulation::getClockMult()
{
	return this->clockMult;
}

string Simulation::getInFile()
{
	return this->inFile;
}
