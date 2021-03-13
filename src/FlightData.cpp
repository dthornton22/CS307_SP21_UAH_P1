// ****************************************
// Program Title: Project1
// Project File: FlightData.cpp
// Name: David Thornton
// Course Section: CS-307, SP 2021
// Due Date: 03/14/2021
// ****************************************
#include "FlightData.h"

Flight::Flight()
{
	
}

Flight::~Flight()
{
	
}

void Flight::readData(string infile)
{

}

void Flight::setFlightNumber(int param)
{
	this->flightNumber = param;
}

void Flight::setDepartTime(int param)
{
	this->departTime = param;
}

void Flight::setAirline(string param)
{
	this->airline = param;
}

void Flight::setAircraftType(string param)
{
	this->aircraftType = param;
}

void Flight::setDepartCity(string param)
{
	this->departCity = param;
}

void Flight::setArriveCity(string param)
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

string Flight::getAirline()
{
	return this->airline;
}

string Flight::getAircraftType()
{
	return this->aircraftType;
}

string Flight::getDepartCity()
{
	return this->departCity;
}

string Flight::getArriveCity()
{
	return this->arriveCity;
}
