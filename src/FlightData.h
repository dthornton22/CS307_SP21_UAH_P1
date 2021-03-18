// ****************************************
// Program Title: Project1
// Project File: FlightData.h
// Name: David Thornton
// Course: CS-307
// Due Date: 03/16/2021
// ****************************************
#include "FlightDataParser.h"
#include "CityDataParser.h"
#include "CityData.h"
#include "AircraftData.h"
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
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
	int StartMin{ 0 };
	int StartHr{ 0 };
	int arrHr{ 0 };
	int arrMin{ 0 };
	vector<Flight> FlightList;

public:
	Flight();
	Flight(char* airline, char* plane, int flNum, char* departCity, int depHr, int depMin, char* destCity);
	~Flight();
	void readData(char* infile);
	vector<Flight> ReturnFlightVector();
	void PrintDeparture(Aircraft A, City C, Flight F, int CurrentHr, int CurrentMin);
	void PrintArrival(City C, Flight F, int CurrentHr, int CurrentMin);
	void PrintAllData(Aircraft A, City C, Flight F, int CurrentHr, int CurrentMin);
	double CurrentLon(double lat1, double lat2, double elapsedTime, double TripTime);
	double CurrentLat(double lon1, double lon2, double elapsedTime, double TripTime);
	double CurrentAlt(double elapsedMin, double ROC);

	// Set functions
	void setFlightNumber(int param);
	void setDepartTimeMin(int param);
	void setDepartTimeHr(int param);
	void setAirline(char param);
	void setAircraftType(char param);
	void setDepartCity(char param);
	void setArriveCity(char param);
	void setArrMin(int param);
	void setArrHr(int param);

	// Get functions
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
