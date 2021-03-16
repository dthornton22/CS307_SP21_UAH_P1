// ****************************************
// Program Title: Project1
// Project File: AircraftData.h
// Name: David Thornton
// Course Section: CS-307, SP 2021
// Due Date: 03/14/2021
// ****************************************
#include "FlightDataParser.h"
#include "CityDataParser.h"
#include <iostream>
#include <vector>
#include <string>
#ifndef AIRCRAFT_H
#define AIRCRAFT_H

using namespace std;

class Aircraft
{
private:
	char make[128];
	char model[128];
	double cruiseSpeed{ 0 };
	double cruiseAltitude{ 0 };
	double climbSpeed{ 0 };
	double wingspan{ 0 };
	double fuselageLength{ 0 };

public:
	Aircraft(char make, char desc,
		double roc, double wngs, double len,
		double cs, double ca); 						// Default constructor
	~Aircraft(); 						// Destructor
	void readData();		// 	

	// Set functions
	void setMake(char param);
	void setModel(char param);
	void setCruiseSpeed(double param);
	void setCruiseAltitude(double param);
	void setClimbSpeed(double param);
	void setWingspan(double param);
	void setFuselageLength(double param);
	// Get functions
	char getMake();
	char getModel();
	double getCruiseSpeed();
	double getCruiseAltitude();
	double getClimbSpeed();
	double getWingspan();
	double getFuselageLength();
};

#endif
