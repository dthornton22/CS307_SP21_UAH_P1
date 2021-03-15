// ****************************************
// Program Title: Project1
// Project File: FlightData.h
// Name: David Thornton
// Course Section: CS-307, SP 2021
// Due Date: 03/14/2021
// ****************************************
#include <string>
#include <iostream>
#include <vector>
#ifndef FLIGHTDATA_H
#define FLIGHTDATA_H

using namespace std;

class Flight
{
	private:
		int flightNumber{0};
		int departTime{0};
		char* airline{};
		char* aircraftType{};
		char* departCity{};
		char* arriveCity{};

	public:
		Flight(); 							// Default constructor
		~Flight(); 							// Destructor
		void readData();					// 

		// Set functions
		void setFlightNumber(int param);
		void setDepartTime(int param);
		void setAirline(char* param);
		void setAircraftType(char* param);
		void setDepartCity(char* param);
		void setArriveCity(char* param);

		// Get functions
		int getFlightNumber();
		int getDepartTime();
		char* getAirline();
		char* getAircraftType();
		char* getDepartCity();
		char* getArriveCity();
};

#endif
