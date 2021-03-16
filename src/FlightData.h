// ****************************************
// Program Title: Project1
// Project File: FlightData.h
// Name: David Thornton
// Course Section: CS-307, SP 2021
// Due Date: 03/14/2021
// ****************************************
#include "FlightDataParser.h"
#include "CityDataParser.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#ifndef FLIGHTDATA_H
#define FLIGHTDATA_H

using namespace std;

class Flight
{
	private:
		int flightNumber{0};
		int departTimeMin{ 0 };
		int departTimeHr{ 0 };
		char airline[128];
		char aircraftType[128];
		char departCity[128];
		char arriveCity[128];
		int StartMin{0};
		int StartHr{ 0 };
		vector<Flight> FlightList;

	public:
		Flight(char airline, char plane,
			int flNum, char departCity, int depHr,
			int depMin, char destCity); 							// Default constructor
		~Flight(); 							// Destructor
		void readData();					// 

		// Set functions
		void setFlightNumber(int param);
		void setDepartTimeMin(int param);
		void setDepartTimeHr(int param);
		void setAirline(char param);
		void setAircraftType(char param);
		void setDepartCity(char param);
		void setArriveCity(char param);
		void PrintDeparture(int CurrentHr, int CurrentMin);
		void PrintArrival(int CurrentHr, int CurrentMin);

		// Get functions
		int getFlightNumber();
		int getDepartMin();
		int getDepartHour();
		int getStartHr();
		int getStartMin();
		char getAirline();
		char getAircraftType();
		char getDepartCity();
		char getArriveCity();
};

#endif
