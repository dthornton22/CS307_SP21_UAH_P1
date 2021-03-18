// ****************************************
// Program Title: Programming Assignment 1
// Project File: FlightData.cpp
// Name: David Thornton
// Course: CS-307
// Due Date: 03/17/2021
// ****************************************
#include "FlightData.h"
#pragma warning(disable : 4996)

Flight::Flight()
{
}

Flight::Flight(char* al, char* plane, int flNum, char* depCity, int depHr, int depMin, char* dstCity, int AMin, int AHr)
{
	strcpy(airline, al);
	strcpy(aircraftType, plane);
	this->flightNumber = flNum;
	strcpy(departCity, depCity);
	this->departTimeHr = depHr;
	this->departTimeMin = depMin;
	this->arrHr = AHr;
	this->arrMin = AMin;
	strcpy(arriveCity, dstCity);
}

Flight::~Flight()
{
}

void Flight::readData(char* infile)
{
	FlightDataParser* ParseFlight = new FlightDataParser();
	ParseFlight->InitFlightData(infile);
	const int FlightCount = ParseFlight->getFlightCount();
	for (int i = 0; i < FlightCount; i++)
	{
		ParseFlight->getFlightData(airline, aircraftType, &flightNumber, departCity, &departTimeHr, &departTimeMin, arriveCity);
		Flight* NewFlight = new Flight(airline, aircraftType, flightNumber, departCity, departTimeHr, departTimeMin, arriveCity, arrMin, arrHr);
		FlightList.push_back(*NewFlight);
	}
	ParseFlight->getStartTime(&startHr, &startMin);
}

vector<Flight> Flight::ReturnFlightVector()
{
	return this->FlightList;
}

void Flight::printAllData(Aircraft A, City C, Flight F, int CurrentHr, int CurrentMin)
{
	vector<Aircraft> AircraftData = A.returnAircraftList();
	vector<City> CityData = C.ReturnCityVector();
	double tempDistance = C.calcDistance(F.getDepartCity(), F.getArriveCity());
	//double tempElapsedTimeHr = CurrentHr - F.getDepartHour();
	//double tempElapsedTimeMin = CurrentMin - F.getDepartMin();
	double tempElapsedTime, tempCurrentLon, tempCurrentLat, tempSpeed, tempTripTime;
	int tempHour, tempMin;
	printf("%s Flight %d - %s\n", F.getAirline(), F.getFlightNumber(), F.getAircraftType());

	// Time of flight calculation
	for (auto& it : AircraftData)
	{
		if (strcmp(F.getAircraftType(), it.getMake()) == 0)
		{
			tempTripTime = C.TripTime(tempDistance, it.getCruiseSpeed());
			tempSpeed = it.getCruiseSpeed();
		}
	}

	for (auto& it : CityData)
	{
		if (strcmp(it.getSymbol(), F.getArriveCity()) == 0)
		{
			printf("\t\tArrives: %s (%.2f, %.2f) at", it.getSymbol(), it.getLatitude(), it.getLongitude());
		}
	}

	for (auto& it : AircraftData)
	{
		if (strcmp(F.getAircraftType(), it.getMake()) == 0)
		{
			tempSpeed = it.getCruiseSpeed();
		}
	}
	double eta = (tempDistance / tempSpeed);
	int hours = int(floor(eta));
	double temp = eta - floor(eta);
	int min = int(round(temp * 60));

	if ((F.getDepartHour() + hours) >= 24) {
		tempHour = 0;
	}
	else
	{
		tempHour = F.getDepartHour() + hours;
	}
	if ((F.getDepartMin() + min) >= 60) {
		tempMin = (F.getDepartMin() + min) - 60;
		tempHour++;
	}
	else {
		tempMin = F.getDepartMin() + min;
	}
	if (tempHour <= 9 && tempMin <= 9) { printf(" %0d:%0d\n", tempHour, tempMin); }
	else if (tempHour <= 9 && tempMin >= 10) { printf(" %0d:%d\n", tempHour, tempMin); }
	else if (tempHour >= 10 && tempMin <= 9) { printf(" %d:%0d\n", tempHour, tempMin); }
	else if (tempHour >= 10 && tempMin >= 10) { printf(" %d:%d\n", tempHour, tempMin); }

	//printf("\t\tCurrent location: (%f, %f)\n", CurrentLocLat, CurrentLocLon); // double // double
	//printf("\t\t\t\t%f miles from %s, %f miles to %s", DepDistance, DepSymbol, DstDistance, DstSymbol); // double // char // double // char
	for (auto& it : AircraftData)
	{
		if (strcmp(F.getAircraftType(), it.getMake()) == 0)
		{
			printf("\t\tCurrent Speed: %.2f MPH\n", it.getCruiseSpeed());
		}
	}
	for (auto& it : AircraftData)
	{
		if (strcmp(F.getAircraftType(), it.getMake()) == 0)
		{
			printf("\t\tCurrent Speed: %.2f MPH\n", it.getCruiseAltitude());
		}
	}
}

void Flight::printDeparture(Aircraft A, City C, Flight F, int CurrentHr, int CurrentMin)
{
	printf("now departing: %s flight %d, %s\n", F.getAirline(), F.getFlightNumber(), F.getAircraftType());
	vector<City> tempCity = C.ReturnCityVector();
	vector<Aircraft> tempAircraft = A.returnAircraftList();
	for (auto& it : tempCity)
	{
		if (strcmp(it.getSymbol(), F.getDepartCity()) == 0)
		{
			printf("\t\tfrom %s, %s\n", it.getName(), it.getState());
		}
	}
	for (auto& it : tempCity)
	{
		if (strcmp(it.getSymbol(), F.getArriveCity()) == 0)
		{
			printf("\t\ten route to %s, %s\n", it.getName(), it.getState());
		}
	}

	double tempDistance = C.calcDistance(F.getDepartCity(), F.getArriveCity());
	double tempSpeed;
	int tempHour = 0;
	int tempMin = 0;
	for (auto& it : tempAircraft)
	{
		if (strcmp(F.getAircraftType(), it.getMake()) == 0)
		{
			tempSpeed = it.getCruiseSpeed();
		}
	}

	double eta = (tempDistance / tempSpeed);
	int hours = int(floor(eta));
	double temp = eta - floor(eta);
	int min = int(round(temp * 60));
	if ((CurrentHr + hours) >= 24) {
		tempHour = 0;
	}
	else
	{
		tempHour = CurrentHr + hours;
	}
	if ((CurrentMin + min) >= 60) {
		tempMin = (CurrentMin + min) - 60;
		tempHour++;
	}
	else
	{
		tempMin = CurrentMin + min;
	}
	if (tempHour <= 9 && tempMin <= 9) { printf("Estimated Time of Arrival: %0d:0%d\n", tempHour, tempMin); }
	else if (tempHour <= 9 && tempMin >= 10) { printf("\tEstimated Time of Arrival: %0d:%d\n", tempHour, tempMin); }
	else if (tempHour >= 10 && tempMin <= 9) { printf("\tEstimated Time of Arrival: %d:0%d\n", tempHour, tempMin); }
	else if (tempHour >= 10 && tempMin >= 10) { printf("\tEstimated Time of Arrival: %d:%d\n", tempHour, tempMin); }
}

void Flight::printArrival(City C, Flight F, int CurrentHr, int CurrentMin)
{
	printf("Now arriving: %s Flight %d, %s\n", F.getAirline(), F.getFlightNumber(), F.getAircraftType());
	vector<City> temp = C.ReturnCityVector();
	for (auto& it : temp)
	{
		if (strcmp(it.getSymbol(), F.getArriveCity()) == 0)
		{
			printf("\t\tAt %s, %s\n", it.getName(), it.getState());
		}
	}
	for (auto& it : temp)
	{
		if (strcmp(it.getSymbol(), F.getDepartCity()) == 0)
		{
			printf("\t\from %s, %s\n", it.getName(), it.getState());
		}
	}
}

int Flight::calcETAMin(Flight F, Aircraft A, City C, int CurrentHr, int CurrentMin)
{
	vector<Aircraft> tempAircraft = A.returnAircraftList();
	double tempDistance = C.calcDistance(F.getDepartCity(), F.getArriveCity());
	double tempSpeed;
	int tempHour = 0;
	int tempMin = 0;
	for (auto& it : tempAircraft)
	{
		if (strcmp(F.getAircraftType(), it.getMake()) == 0)
		{
			tempSpeed = it.getCruiseSpeed();
		}
	}

	double eta = (tempDistance / tempSpeed);
	int hours = int(floor(eta));
	double temp = eta - floor(eta);
	int min = int(round(temp * 60));
	if ((CurrentHr + hours) >= 24) {
		tempHour = 0;
	}
	else
	{
		tempHour = CurrentHr + hours;
	}
	if ((CurrentMin + min) >= 60) {
		tempMin = (CurrentMin + min) - 60;
		tempHour++;
	}
	else
	{
		tempMin = CurrentMin + min;
	}
	return tempMin;
}

int Flight::calcETAHr(Flight F, Aircraft A, City C, int CurrentHr, int CurrentMin)
{
	vector<Aircraft> tempAircraft = A.returnAircraftList();
	double tempDistance = C.calcDistance(F.getDepartCity(), F.getArriveCity());
	double tempSpeed;
	int tempHour = 0;
	int tempMin = 0;
	for (auto& it : tempAircraft)
	{
		if (strcmp(F.getAircraftType(), it.getMake()) == 0)
		{
			tempSpeed = it.getCruiseSpeed();
		}
	}

	double eta = (tempDistance / tempSpeed);
	int hours = int(floor(eta));
	double temp = eta - floor(eta);
	int min = int(round(temp * 60));
	if ((CurrentHr + hours) >= 24) {
		tempHour = 0;
	}
	else
	{
		tempHour = CurrentHr + hours;
	}
	if ((CurrentMin + min) >= 60) {
		tempMin = (CurrentMin + min) - 60;
		tempHour++;
	}
	else
	{
		tempMin = CurrentMin + min;
	}
	return tempHour;
}

double Flight::curLat(double lat1, double lat2, double elapsedTime, double TripTime)
{
	return lat1 + (lat2 - lat1) * (elapsedTime / TripTime);
}

double Flight::curLon(double lon1, double lon2, double elapsedTime, double TripTime)
{
	return lon1 + (lon2 - lon1) * (elapsedTime / TripTime);
}

double Flight::curAlt(double elapsedMin, double ROC)
{
	return elapsedMin / ROC;
}

int Flight::getFlightNumber()
{
	return this->flightNumber;
}

int Flight::getDepartMin()
{
	return this->departTimeMin;
}

int Flight::getDepartHour()
{
	return this->departTimeHr;
}

char* Flight::getAirline()
{
	return this->airline;
}

char* Flight::getAircraftType()
{
	return this->aircraftType;
}

char* Flight::getDepartCity()
{
	return this->departCity;
}

char* Flight::getArriveCity()
{
	return this->arriveCity;
}

int Flight::getStartMin()
{
	return this->startMin;
}

int Flight::getStartHr()
{
	return this->startHr;
}

void Flight::setArrMin(int param)
{
	this->arrMin = param;
}

void Flight::setArrHr(int param)
{
	this->arrHr = param;
}

int Flight::getArrHr()
{
	return this->arrHr;
}

int Flight::getArrMin()
{
	return this->arrMin;
}
