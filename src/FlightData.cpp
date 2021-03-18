// ****************************************
// Program Title: Project1
// Project File: FlightData.cpp
// Name: David Thornton
// Course: CS-307
// Due Date: 03/16/2021
// ****************************************
#include "FlightData.h"
#pragma warning(disable : 4996)

Flight::Flight()
{
}

Flight::Flight(char* al, char* plane, int flNum, char* depCity, int depHr, int depMin, char* dstCity)
{
	strcpy(airline, al);
	strcpy(aircraftType, plane);
	this->flightNumber = flNum;
	strcpy(departCity, depCity);
	this->departTimeHr = depHr;
	this->departTimeMin = depMin;
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
		Flight* NewFlight = new Flight(airline, aircraftType, flightNumber, departCity, departTimeHr, departTimeMin, arriveCity);
		FlightList.push_back(*NewFlight);
	}
	ParseFlight->getStartTime(&StartHr, &StartMin);
}

vector<Flight> Flight::ReturnFlightVector()
{
	return this->FlightList;
}

void Flight::PrintAllData(Aircraft A, City C, Flight F, int CurrentHr, int CurrentMin)
{
	vector<Aircraft> AircraftData = A.ReturnAircraftList();								// Vector of Aircraft data
	vector<City> CityData = C.ReturnCityVector();										// Vector of city data
	double tempDistance = C.calcDistance(F.getDepartCity(), F.getArriveCity());			// Distance
	double tempTripTime;
	double tempElapsedTimeHr = CurrentHr - F.getDepartHour();
	double tempElapsedTimeMin = CurrentMin - F.getDepartMin();
	double tempElapsedTime;
	double tempCurrentLon;
	double tempCurrentLat;
	double tempSpeed;

	int tempHour;
	int tempMin;

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
	else {
		tempMin = CurrentMin + min;
	}

	// Departs from...
	for (auto& it : CityData)
	{
		if (strcmp(it.getSymbol(), F.getDepartCity()) == 0)
		{
			printf("\t\tDeparts: %s (%f, %f) at %d:%d\n", F.getDepartCity(), it.getLatitude(), it.getLongitude(), F.getDepartHour(), F.getDepartMin());
		}
	}

	// Arrives at...
	for (auto& it : CityData)
	{
		if (strcmp(it.getSymbol(), F.getArriveCity()) == 0)
		{
			printf("\t\tArrives: %s (%f, %f) at", it.getSymbol(), it.getLatitude(), it.getLongitude());
			if (tempHour <= 9 && tempMin <= 9) { printf(" %0d:%0d\n", tempHour, tempMin); }// ex 07:00
			else if (tempHour <= 9 && tempMin >= 10) { printf(" %0d:%d\n", tempHour, tempMin); }// ex 07:10
			else if (tempHour >= 10 && tempMin <= 9) { printf(" %d:%0d\n", tempHour, tempMin); }// ex 10:00
			else if (tempHour >= 10 && tempMin >= 10) { printf(" %d:%d\n", tempHour, tempMin); }// ex 10:11
		}
	}

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

void Flight::PrintDeparture(Aircraft A, City C, Flight F, int CurrentHr, int CurrentMin)
{
	printf("now departing: %s flight %d, %s\n", F.getAirline(), F.getFlightNumber(), F.getAircraftType());
	vector<City> tempCity = C.ReturnCityVector();
	vector<Aircraft> tempAircraft = A.ReturnAircraftList();
	for (auto& it : tempCity)
	{
		if (strcmp(it.getSymbol(), F.getDepartCity()) == 0)	// if the symbol is equal to the departure city symbol
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

	double tempSpeed;
	int tempHour = 0;
	int tempMin = 0;
	for (auto& it : tempAircraft)
	{
		if (strcmp(it.getMake(), F.getAircraftType()) == 0) {
			tempSpeed = it.getCruiseSpeed();
		}
	}

	double tempDistance = C.calcDistance(F.getDepartCity(), F.getArriveCity());			// Distance
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
	else {
		tempMin = CurrentMin + min;
	}

	F.setArrMin(tempMin);
	F.setArrHr(tempHour);

	if (tempHour <= 9 && tempMin <= 9) { printf("Current clock time: %0d:0%d\n", tempHour, tempMin); }// ex 07:00
	else if (tempHour <= 9 && tempMin >= 10) { printf("\tEstimated Time of Arrival: %0d:%d\n", tempHour, tempMin); }// ex 07:10
	else if (tempHour >= 10 && tempMin <= 9) { printf("\tEstimated Time of Arrival: %d:0%d\n", tempHour, tempMin); }// ex 10:00
	else if (tempHour >= 10 && tempMin >= 10) { printf("\tEstimated Time of Arrival: %d:%d\n", tempHour, tempMin); }// ex 10:11
}

double Flight::CurrentLat(double lat1, double lat2, double elapsedTime, double TripTime)
{
	return lat1 + (lat2 - lat1) * (elapsedTime / TripTime);
}

double Flight::CurrentLon(double lon1, double lon2, double elapsedTime, double TripTime)
{
	return lon1 + (lon2 - lon1) * (elapsedTime / TripTime);
}

double Flight::CurrentAlt(double elapsedMin, double ROC)
{
	return elapsedMin / ROC;
}

void Flight::PrintArrival(City C, Flight F, int CurrentHr, int CurrentMin)
{
	printf("Now arriving: %s Flight %d, %s\n", F.getAirline(), F.getFlightNumber(), F.getAircraftType());
	vector<City> temp = C.ReturnCityVector();
	for (auto& it : temp)
	{
		if (strcmp(it.getSymbol(), F.getArriveCity()) == 0)	// if the symbol is equal to the departure city symbol
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

void Flight::setFlightNumber(int param)
{
	this->flightNumber = param;
}

void Flight::setDepartTimeMin(int param)
{
	this->departTimeMin = param;
}

void Flight::setDepartTimeHr(int param)
{
	this->departTimeHr = param;
}

void Flight::setAirline(char param)
{
	*this->airline = param;
}

void Flight::setAircraftType(char param)
{
	*this->aircraftType = param;
}

void Flight::setDepartCity(char param)
{
	*this->departCity = param;
}

void Flight::setArriveCity(char param)
{
	*this->arriveCity = param;
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
	return this->StartMin;
}

int Flight::getStartHr()
{
	return this->StartHr;
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
