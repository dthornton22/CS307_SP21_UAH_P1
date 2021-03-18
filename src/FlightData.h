// ****************************************
// Program Title: Programming Assignment 1
// Project File: FlightData.h
// Name: David Thornton
// Course: CS-307
// Due Date: 03/17/2021
// ****************************************
#include "FlightDataParser.h"
#include "CityDataParser.h"
#include "CityData.h"
#include "AircraftData.h"
#include <math.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#ifndef FLIGHTDATA_H
#define FLIGHTDATA_H

using namespace std;

class Flight
{
private:
	int flightNumber{ 0 };
	int departTimeMin{ 0 };
	int departTimeHr{ 0 };
	char airline[128] = {};
	char aircraftType[128] = {};
	char departCity[128] = {};
	char arriveCity[128] = {};
	int startMin{ 0 };
	int startHr{ 0 };
	int arrHr{ 0 };
	int arrMin{ 0 };
	vector<Flight> FlightList;

public:
	Flight();
	Flight(char* airline, char* plane, int flNum, char* departCity, int depHr, int depMin, char* destCity, int AMin, int AHr);
	~Flight();
	void readData(char* infile);
	vector<Flight> ReturnFlightVector();
	void printDeparture(Aircraft A, City C, Flight F, int CurrentHr, int CurrentMin);
	void printArrival(City C, Flight F, int CurrentHr, int CurrentMin);
	void printAllData(Aircraft A, City C, Flight F, int CurrentHr, int CurrentMin);
	double curLon(double lat1, double lat2, double elapsedTime, double TripTime);
	double curLat(double lon1, double lon2, double elapsedTime, double TripTime);
	double curAlt(double elapsedMin, double ROC);
	void setArrMin(int param);
	void setArrHr(int param);
	int calcETAMin(Flight F, Aircraft A, City C, int CurrentHr, int CurrentMin);
	int calcETAHr(Flight F, Aircraft A, City C, int CurrentHr, int CurrentMin);
	int getFlightNumber();
	int getDepartMin();
	int getDepartHour();
	int getStartHr();
	int getStartMin();
	int getArrHr();
	int getArrMin();
	char* getAirline();
	char* getAircraftType();
	char* getDepartCity();
	char* getArriveCity();
};

#endif
