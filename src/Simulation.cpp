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
	printf("\nPlease enter the name of the simulation data file\n");
	getline(cin, inputFile);
	char* inFileCharArray = &inputFile[0];
	FILE* filepoint;

	if ((fopen_s(&filepoint, inFileCharArray, "r")) != 0)
	{
		cout << "Cannot open file " << inputFile << endl;
		cout << "Exiting program now..." << endl;
		exit(1);
	}
	else
	{
		cout << "Successfully opened file " << inputFile << endl;
		cout << "Initializing simulation..." << endl;
	}
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
	testFlight->PrintDeparture(07, 44);
	//testFlight->PrintArrival(07, 35);
}

void Simulation::runSimulation(double clocktime)
{
	_ftime_s(&tStruct);	// Get start time
	thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
	outputTime = thisTime + 1.0/clocktime; // Set next 1 second interval time (we could add, e.g., .5 to delay just a half second)

	while (!done)     // Start an eternal loop
	{
		_ftime_s(&tStruct);    // Get the current time
		thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
		// Check for 1 second interval to print status to screen
		if (thisTime >= outputTime)
		{
			printReport();     // Call function to print all data
			outputTime += 1.0/clocktime; // Set time for next 1 second interval
		}
		// Do other stuff here
	}
}

void Simulation::initializeSimulation()
{
	printf("\nWhat speed do you want to run the simulation? (1, 2, or 3)\n");
	cin >> clockMult;
}

void Simulation::setClockMult(int param)
{
	this->clockMult = param;
}

void Simulation::setInFile(string param)
{
	this->inputFile = param;
}

int Simulation::getClockMult()
{
	return this->clockMult;
}

string Simulation::getInFile()
{
	return this->inputFile;
}
