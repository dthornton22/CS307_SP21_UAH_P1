// ****************************************
// Program Title: Project1
// Project File: FlightData.cpp
// Name: David Thornton
// Course Section: CS-307, SP 2021
// Due Date: 03/14/2021
// ****************************************
#include "FlightData.h"
#include "FlightDataParser.h"

Flight::Flight()
{
	Flight::readData();
}

Flight::~Flight()
{
	
}

void Flight::readData()
{
	FlightDataParser* ParseFlight = new FlightDataParser();
	ParseFlight->InitFlightData("C:/Users/David Thornton/source/repos/CS307Project1/src/Data/AirlineFlightData01.xml");
	vector<Flight> FlightList;
	printf("Number of flights: %d\n", ParseFlight->getFlightCount()); // test

}

void Flight::setFlightNumber(int param)
{
	this->flightNumber = param;
}

void Flight::setDepartTime(int param)
{
	this->departTime = param;
}

void Flight::setAirline(char* param)
{
	this->airline = param;
}

void Flight::setAircraftType(char* param)
{
	this->aircraftType = param;
}

void Flight::setDepartCity(char* param)
{
	this->departCity = param;
}

void Flight::setArriveCity(char* param)
{
	this->arriveCity = param;
}

int Flight::getFlightNumber()
{
	return this->flightNumber;
}

int Flight::getDepartTime()
{
	return this->departTime;
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
