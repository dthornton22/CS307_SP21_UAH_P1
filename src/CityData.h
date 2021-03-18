// ****************************************
// Program Title: Project1
// Project File: CityData.h
// Name: Nolan Anderson
// Course: CS-307
// Due Date: 03/17/2021
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
	char name[128] = {};
	char state[128] = {};
	char sym[128] = {};
	double latitude{ 0 };
	double longitude{ 0 };
	vector<City> CityList;
	double* distances;
	char** symbols;
	int CityCount;

public:
	City();
	City(char* name, char* state, char* symbol, double lat, double lon);
	~City();
	void readData(char* infile);
	double calcDistance(char *dep, char *arr);
	double TripTime(double Distance, double CruiseSpeed);
	double DistFromStart(double Distance, double TripTime, double Elapsed);
	double DistToDst(double DistFromStart, double calcDistance);

	// Set functions
	void setName(char param);
	void setState(char param);
	void setSymbol(char param);
	void setLatitude(double param);
	void setLongitude(double param);
	vector<City> ReturnCityVector();

	// Get functions
	char* getName();
	char* getState();
	char* getSymbol();
	double getLatitude();
	double getLongitude();
};

#endif
