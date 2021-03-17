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
	//testFlight->PrintDeparture(07, 44);
	//testFlight->PrintArrival(07, 35);
}

void Simulation::runSimulation(double clocktime)
{
	_ftime_s(&tStruct);	// Get start time
	thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
	outputTime = thisTime + 1.0/clocktime; // Set next 1 second interval time (we could add, e.g., .5 to delay just a half second)

	while (1)     // Start an eternal loop
	{
		_ftime_s(&tStruct);    // Get the current time
		thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
		// Check for 1 second interval to print status to screen
		if (thisTime >= outputTime)
		{
			CurrentMin += 1;
			counter += 1;
			if (CurrentMin == testFlight->getDepartMin() && CurrentHr == testFlight->getDepartHour())
			{
				printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				testFlight->PrintDeparture(CurrentMin, CurrentHr);
				PrintCurrentTime();
				printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

				// increment the list for the next flight.
			}

			if ((counter % 5) == 0)
			{
				printf("================================================================\n");
				printf("|  Flight Simulation - Status reports on all flights enroute.  |\n");
				printf("================================================================\n");
				testFlight->PrintAllData(CurrentHr, CurrentMin);
				PrintCurrentTime();
				printf("================================================================\n");
			}

			// Need to write get functions for the arrival times
			//if (CurrentHr == testFlight->getArriveHr() && CurrentMin == testFlight->getArrivalMin())	
			//{
			//	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			//	testFlight->PrintArrival(CurrentMin, CurrentHr);
			//	PrintCurrentTime();
			//	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			//}
			if (CurrentMin >= 60)		// Check for minute overflow
			{
				CurrentHr += 1;
				if (CurrentHr == 13)	// Check for hour overflow
				{
					CurrentHr = 1;
				}
				CurrentMin = 0;
			}
			outputTime += 1.0/clocktime; // Set time for next 1 second interval
		}
		// Do other stuff here
	}
}

void Simulation::initializeSimulation()
{
	printf("\nWhat speed do you want to run the simulation? (1, 2, or 3)\n");
	cin >> clockMult;
	// Start with default values
	testCity = new City(char(0), char(0), char(0), 0, 0);
	testFlight = new Flight(char(0), char(0), 0, char(0), 0, 0, char(0));
	testAircraft = new Aircraft(char(0), char(0), 0, 0, 0, 0, 0);
	// Then read in the data
	testCity->readData();
	testFlight->readData();
	testAircraft->readData();
	// Get start time
	CurrentHr = testFlight->getStartHr();
	CurrentMin = testFlight->getStartMin();
	PrintStartTime();
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

void Simulation::PrintCurrentTime()
{
	if (CurrentHr <= 9 && CurrentMin <= 9) { printf("Current clock time: %0d:0%d\n", CurrentHr, CurrentMin); }		// ex 07:00
	else if (CurrentHr <= 9 && CurrentMin >= 10) { printf("Current clock time: %0d:%d\n", CurrentHr, CurrentMin); }// ex 07:10
	else if (CurrentHr >= 10 && CurrentMin <= 9) { printf("Current clock time: %d:0%d\n", CurrentHr, CurrentMin); }// ex 10:00
	else if (CurrentHr >= 10 && CurrentMin >= 10) { printf("Current clock time: %d:%d\n", CurrentHr, CurrentMin); }// ex 10:11
}

void Simulation::PrintStartTime()
{
	if (CurrentHr <= 9 && CurrentMin <= 9) { printf("*** Starting simulation at 0%d:0%d ***\n", CurrentHr, CurrentMin); }     // ex 07:00
	else if (CurrentHr <= 9 && CurrentMin >= 10) { printf("*** Starting simulation at 0%d:%d ***\n", CurrentHr, CurrentMin); }// ex 07:10
	else if (CurrentHr >= 10 && CurrentMin <= 9) { printf("*** Starting simulation at %d:0%d ***\n", CurrentHr, CurrentMin); }// ex 10:00
	else if (CurrentHr >= 10 && CurrentMin >= 10) { printf("*** Starting simulation at %d:%d ***\n", CurrentHr, CurrentMin); }// ex 10:11
}
