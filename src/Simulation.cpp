// ****************************************
// Program Title: Project1
// Project File: Simulation.cpp
// Name: David Thornton
// Course: CS-307
// Due Date: 03/16/2021
// ****************************************
#pragma warning(disable : 4996)

#include "Simulation.h"

Simulation::Simulation()
{
}

Simulation::~Simulation()
{
}

double Simulation::getFlightETA()
{
	return 0;
}


void Simulation::PrintCurrentTime()
{
	if      (CurrentHr <= 9 && CurrentMin <= 9) { printf("Current clock time: %0d:0%d\n", CurrentHr, CurrentMin); }// ex 07:00
	else if (CurrentHr <= 9 && CurrentMin >= 10) { printf("Current clock time: %0d:%d\n", CurrentHr, CurrentMin); }// ex 07:10
	else if (CurrentHr >= 10 && CurrentMin <= 9) { printf("Current clock time: %d:0%d\n", CurrentHr, CurrentMin); }// ex 10:00
	else if (CurrentHr >= 10 && CurrentMin >= 10) { printf("Current clock time: %d:%d\n", CurrentHr, CurrentMin); }// ex 10:11
}

void Simulation::PrintStartTime()
{
	if      (CurrentHr <= 9 && CurrentMin <= 9) { printf("*** Starting simulation at 0%d:0%d ***\n", CurrentHr, CurrentMin); }// ex 07:00
	else if (CurrentHr <= 9 && CurrentMin >= 10) { printf("*** Starting simulation at 0%d:%d ***\n", CurrentHr, CurrentMin); }// ex 07:10
	else if (CurrentHr >= 10 && CurrentMin <= 9) { printf("*** Starting simulation at %d:0%d ***\n", CurrentHr, CurrentMin); }// ex 10:00
	else if (CurrentHr >= 10 && CurrentMin >= 10) { printf("*** Starting simulation at %d:%d ***\n", CurrentHr, CurrentMin); }// ex 10:11
}

void Simulation::initializeSimulation()
{
	printf("==============================================================\n");
	printf("|          AIRLINE FLIGHT SIMULATION DEMONSTRATION           |\n");
	printf("|            CS 307 -- Programming Assignment 1              |\n");
	printf("==============================================================\n");
	printf("\nPlease enter the name of the simulation data file\n");
	getline(cin, inputFile); // default is ../FlightSim01.txt
	char* inFileCharArray = &inputFile[0];
	ifstream userInFile(inFileCharArray);
	string cityFile, flightFile;
	char myCityFile[32];
	char myFlightFile[32];

	if (!userInFile)
	{
		cout << "Cannot open file " << inputFile << endl;
		cout << "Exiting program now..." << endl;
		exit(1);
	}
	else
	{
		cout << "Successfully opened file " << inputFile << endl;
		getline(userInFile, cityFile);
		getline(userInFile, flightFile);
		cout << "Opening City data file " << cityFile << "..." << endl;
		cout << "Opening Airline/Flight data file " << flightFile << "..." << endl;

		string temp1 = "../" + cityFile;
		string temp2 = "../" + flightFile;
		strcpy(myCityFile, temp1.c_str());
		strcpy(myFlightFile, temp2.c_str());

		cout << "Initializing simulation..." << endl;
	}
	printf("\nWhat speed do you want to run the simulation? (1, 2, or 3)\n");
	cin >> clockMult;
	if (clockMult > 3 || clockMult < 1)
	{
		cout << "Error!! Invalid simulation speed" << endl;
		cout << "Exiting program now..." << endl;
		exit(2);
	}

	// Start with default values
	testCity = new City();
	testFlight = new Flight();
	testAircraft = new Aircraft(char(0), char(0), 0, 0, 0, 0, 0);

	// Then read in the data

	testCity->readData(myCityFile);
	testFlight->readData(myFlightFile);
	testAircraft->readData(myFlightFile);

	// Get start time
	CurrentHr = testFlight->getStartHr();
	CurrentMin = testFlight->getStartMin();
	PrintStartTime();
}

void Simulation::runSimulation(double clocktime)
{
	_ftime_s(&tStruct);	// Get start time
	thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
	outputTime = thisTime + 1.0 / clocktime; // Set next 1 second interval time (we could add, e.g., .5 to delay just a half second)
	vector<Flight> InAir;
	while (1)     // Start an infinite loop
	{
		_ftime_s(&tStruct);    // Get the current time
		thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
		// Check for 1 second interval to print status to screen
		if (thisTime >= outputTime)
		{
			CurrentMin += 1;
			Counter += 1;
			
			vector<Flight> Data = testFlight->ReturnFlightVector();
			vector<City> CityVector = testCity->ReturnCityVector();
			// Output a new flight.
			for (auto &it : Data)
			{
				int tempHr = it.getDepartHour();
				int tempMin = it.getDepartMin();
				if (CurrentHr == tempHr && CurrentMin == tempMin)
				{
					printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
					testFlight->PrintDeparture(*testCity, it, CurrentMin, CurrentHr);
					PrintCurrentTime();
					printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
					Flight NewInAir(it.getAirline(), it.getAircraftType(), it.getFlightNumber(), it.getDepartCity(), it.getDepartHour(), it.getDepartMin(), it.getArriveCity());
					InAir.push_back(NewInAir);
				}
			}

			// Output all current flights. 
			if ((Counter % 5) == 0)
			{
				printf("================================================================\n");
				printf("|  Flight Simulation - Status reports on all flights enroute.  |\n");
				printf("================================================================\n");
				for (auto &all : InAir)
				{
					testFlight->PrintAllData(all, CurrentHr, CurrentMin);
				}
				PrintCurrentTime();
				printf("================================================================\n");
			}


			// Output arriving flights.

			// Need to write get functions for the arrival times
			//if (CurrentHr == testFlight->getArriveHr() && CurrentMin == testFlight->getArrivalMin())
			//{
			//	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			//	testFlight->PrintArrival(CurrentMin, CurrentHr);
			//	PrintCurrentTime();
			//	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			//}

			// Increment time.
			if (CurrentMin >= 60)		// Check for minute overflow
			{
				CurrentHr += 1;
				if (CurrentHr == 13)	// Check for hour overflow
				{
					CurrentHr = 1;
				}
				CurrentMin = 0;
			}
			outputTime += 1.0 / clocktime; // Set time for next 1 second interval
		}
	}
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
