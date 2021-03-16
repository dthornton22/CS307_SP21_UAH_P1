// ****************************************
// Program Title: Project1
// Project File: CityData.h
// Name: David Thornton
// Course Section: CS-307, SP 2021
// Due Date: 03/14/2021
// ****************************************
#include "FlightDataParser.h"
#include "CityDataParser.h"
#include <iostream>
#include <string>
#include <vector>
#ifndef CITY_H
#define CITY_H

using namespace std;

class City
{
	private:
		char name[128];
		char state[128];
		char sym[128];
		double latitude{0};
		double longitude{0};
		int CityCount{ 0 };
		char ** symbols;
		double *distances;

	public:
		City(char name, char state, char symbol, double lat, double lon); 							// Default constructor
		~City(); 							// Destructor
		void readData();					// 
		double calcDistance(char dep, char arr);	// 

		// Set functions
		void setName(char param);
		void setState(char param);
		void setLatitude(double param);
		void setLongitude(double param);
		void setSymbol(char param);
		// Get functions
		char getName();
		char getState();
		char getSymbol();
		double getLatitude();
		double getLongitude();
};

#endif
