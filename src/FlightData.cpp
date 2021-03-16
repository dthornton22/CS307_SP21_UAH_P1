// ****************************************
// Program Title: AircraftRapper
// Project File: FlightData.cpp
// Name: Nolan Anderson
// Course: CS-307
// Due Date: 03/16/2021
// ****************************************
#include "FlightData.h"

Flight::Flight(char airline, char plane,
	int flNum, char departCity, int depHr,
	int depMin, char destCity)
{
	this->flightNumber = flNum;
	this->departTimeHr = depHr;
	this->departTimeMin = depMin;
	this->setAircraftType(plane);
	this->setAirline(airline);
	this->setDepartCity(departCity);
	this->setArriveCity(destCity);
}

Flight::~Flight()
{
	
}

void Flight::readData()
{
	FlightDataParser *ParseFlight = new FlightDataParser();
	ParseFlight->InitFlightData("../AirlineFlightData01.xml");
	const int FlightCount = ParseFlight->getFlightCount();
	for (int i = 0; i < FlightCount; i++)
	{
		ParseFlight->getFlightData(airline, aircraftType, &flightNumber, departCity, &departTimeHr, &departTimeMin, arriveCity);
		Flight *NewFlight = new Flight(*airline, *aircraftType, flightNumber, *departCity, departTimeHr, departTimeMin, *arriveCity);
		FlightList.push_back(*NewFlight);
	}
	ParseFlight->getStartTime(&StartHr, &StartMin);
}

void Flight::PrintDeparture(int CurrentHr, int CurrentMin)
{
	//cout << "TESTING: " << FlightList[0].getAirline() << endl;
	//cout << "TESTING 2: " << FlightList[1].getAirline() << endl;
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("Now departing: %s Flight %d, %s\n", airline, flightNumber, aircraftType);
	printf("                 From %s, %s\n", departCity, "city-state");
	printf("                 En route to %s, %s\n", arriveCity, "city-state");
	printf("                 Estimated Time of Arrival: %d:%d", "call", "time calculation\n");
	printf("Current clock time: %d:%d\n", CurrentHr, CurrentMin);
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void Flight::PrintArrival(int CurrentHr, int CurrentMin)
{
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("Now arriving: %s Flight %d, %s\n", airline, flightNumber, aircraftType);
	printf("                 at %s, %s\n", departCity, "dststatename");
	printf("                 from %s, %s\n", arriveCity, "depstatename");
	printf("Current clock time: %d:%d\n", CurrentHr, CurrentMin);
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
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

char Flight::getAirline()
{
	return *this->airline;
}

char Flight::getAircraftType()
{
	return *this->aircraftType;
}

char Flight::getDepartCity()
{
	return *this->departCity;
}

char Flight::getArriveCity()
{
	return *this->arriveCity;
}

int Flight::getStartMin()
{
	return this->StartMin;
}

int Flight::getStartHr()
{
	return this->StartHr;
}