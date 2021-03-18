// ****************************************
// Program Title: Programming Assignment 1
// Project File: Simulation.cpp
// Name: David Thornton
// Course: CS-307
// Due Date: 03/17/2021
// ****************************************
#include "Simulation.h"
#pragma warning(disable : 4996)

Simulation::Simulation()
{
}

Simulation::~Simulation()
{
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

		string temp1 = "../" + cityFile; // since solution is not in same directory
		string temp2 = "../" + flightFile; // go up a folder to grab these files
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
	myCity = new City();
	myFlight = new Flight();
	myAircraft = new Aircraft();
	myCity->readData(myCityFile);
	myFlight->readData(myFlightFile);
	myAircraft->readData(myFlightFile);
	curHr = myFlight->getStartHr();
	curMin = myFlight->getStartMin();
	printStartTime();
}

void Simulation::runSimulation(double clocktime)
{
	_ftime_s(&tStruct);
	thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0);
	outputTime = thisTime + 1.0 / clocktime;
	vector<Flight> InAir;
	bool finished = false;
	while (!finished)
	{
		_ftime_s(&tStruct);
		thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0);
		if (thisTime >= outputTime)
		{
			curMin += 1;
			counter += 1;

			vector<Flight> Flights = myFlight->ReturnFlightVector();
			vector<Aircraft> Airplanes = myAircraft->returnAircraftList();
			vector<City> Cities = myCity->ReturnCityVector();
			// Increment time
			if (curMin >= 60) // minute overflow
			{
				curHr += 1;
				if (curHr == 13) // hour overflow
				{
					curHr = 1;
				}
				curMin = 0;
			}
			outputTime += 1.0 / clocktime;

			// Output a new flight
			for (auto& it : Flights)
			{
				int tempHr = it.getDepartHour();
				int tempMin = it.getDepartMin();
				if (curHr == tempHr && curMin == tempMin)
				{
					printf("\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
					myFlight->printDeparture(*myAircraft, *myCity, it, curHr, curMin);
					printCurrentTime();
					printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
					Flight NewInAir(it.getAirline(), it.getAircraftType(), it.getFlightNumber(), it.getDepartCity(), it.getDepartHour(), it.getDepartMin(), it.getArriveCity(), it.getArrMin(), it.getArrHr());
					NewInAir.setArrHr(NewInAir.calcETAHr(it, *myAircraft, *myCity, curHr, curMin));
					NewInAir.setArrMin(NewInAir.calcETAMin(it, *myAircraft, *myCity, curHr, curMin));
					InAir.push_back(NewInAir);
				}
			}

			// Output all current flights every 5 minutes
			if ((counter % 5) == 0)
			{
				printf("\n\n================================================================\n");
				printf("|  Flight Simulation - Status reports on all flights enroute.  |\n");
				printf("================================================================\n");
				for (auto& all : InAir)
				{
					myFlight->printAllData(*myAircraft, *myCity, all, curHr, curMin);
				}
				printCurrentTime();
				printf("================================================================\n");
			}

			for (auto& it : InAir)

			{
				if (curHr == it.getArrHr() && curMin == it.getArrMin())
				{
					printf("\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
					myFlight->printArrival(*myCity, it, curMin, curHr);
					printCurrentTime();
					printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
					InAir.erase(InAir.begin());
					if (InAir.empty())
					{
						finished = true;
					}
				}
			}
		}
	}
}

void Simulation::printCurrentTime()
{
	if (curHr <= 9 && curMin <= 9) { printf("Current clock time: %0d:0%d\n", curHr, curMin); }
	else if (curHr <= 9 && curMin >= 10) { printf("Current clock time: %0d:%d\n", curHr, curMin); }
	else if (curHr >= 10 && curMin <= 9) { printf("Current clock time: %d:0%d\n", curHr, curMin); }
	else if (curHr >= 10 && curMin >= 10) { printf("Current clock time: %d:%d\n", curHr, curMin); }
}

void Simulation::printStartTime()
{
	if (curHr <= 9 && curMin <= 9) { printf("*** Starting simulation at 0%d:0%d ***\n", curHr, curMin); }
	else if (curHr <= 9 && curMin >= 10) { printf("*** Starting simulation at 0%d:%d ***\n", curHr, curMin); }
	else if (curHr >= 10 && curMin <= 9) { printf("*** Starting simulation at %d:0%d ***\n", curHr, curMin); }
	else if (curHr >= 10 && curMin >= 10) { printf("*** Starting simulation at %d:%d ***\n", curHr, curMin); }
}

int Simulation::getClockMult()
{
	return this->clockMult;
}
