// ****************************************
// Program Title: Programming Assignment 1
// Project File: AircraftData.h
// Name: David Thornton
// Course: CS-307
// Due Date: 03/17/2021
// ****************************************
#include "FlightDataParser.h"
#include <iostream>
#include <vector>
#include <string>
#ifndef AIRCRAFT_H
#define AIRCRAFT_H

using namespace std;

class Aircraft
{
private:
	char make[128] = {};
	char model[128] = {};
	double cruiseSpeed{ 0 };
	double cruiseAltitude{ 0 };
	double climbSpeed{ 0 };
	double wingspan{ 0 };
	double fuselageLength{ 0 };
	vector<Aircraft> AircraftList;

public:
	Aircraft();
	Aircraft(char* make, char* desc, double roc, double wngs, double len, double cs, double ca);
	~Aircraft();
	void readData(char* infile);
	char* getMake();
	char* getModel();
	double getCruiseSpeed();
	double getCruiseAltitude();
	double getClimbSpeed();
	double getWingspan();
	double getFuselageLength();
	vector<Aircraft> returnAircraftList();
};

#endif
