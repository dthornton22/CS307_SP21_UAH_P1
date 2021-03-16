// ****************************************
// Program Title: Project1
// Project File: AircraftData.cpp
// Name: David Thornton
// Course: CS-307
// Due Date: 03/16/2021
// ****************************************
#include "AircraftData.h"
Aircraft::Aircraft(char make, char desc, double roc, double wngs, double len, double cs, double ca)
{
	this->setMake(make);
	this->setModel(desc);
	this->cruiseSpeed = cs;
	this->cruiseAltitude = ca;
	this->climbSpeed = roc;
	this->wingspan = wngs;
	this->fuselageLength = len;
}

Aircraft::~Aircraft()
{
}

void Aircraft::readData()
{
	FlightDataParser* ParseAircraft = new FlightDataParser();
	ParseAircraft->InitFlightData("AirlineFlightData01.xml");
	int AircraftCount = ParseAircraft->getAircraftCount();
	vector<Aircraft> AircraftList;
	for (int i = 0; i < AircraftCount; i++)
	{
		ParseAircraft->getAircraftData(make, model, &climbSpeed, &wingspan, &fuselageLength, &cruiseSpeed, &cruiseAltitude);
		Aircraft NewAircraft(*make, *model, climbSpeed, wingspan, fuselageLength, cruiseSpeed, cruiseAltitude);
		AircraftList.push_back(NewAircraft);
	}
}

void Aircraft::setMake(char param)
{
	*this->make = param;
}

void Aircraft::setModel(char param)
{
	*this->model = param;
}

void Aircraft::setCruiseSpeed(double param)
{
	this->cruiseAltitude = param;
}

void Aircraft::setCruiseAltitude(double param)
{
	this->cruiseAltitude = param;
}

void Aircraft::setClimbSpeed(double param)
{
	this->climbSpeed = param;
}

void Aircraft::setWingspan(double param)
{
	this->wingspan = param;
}

void Aircraft::setFuselageLength(double param)
{
	this->fuselageLength = param;
}

char Aircraft::getMake()
{
	return *this->make;
}

char Aircraft::getModel()
{
	return *this->model;
}

double Aircraft::getCruiseSpeed()
{
	return this->cruiseSpeed;
}

double Aircraft::getCruiseAltitude()
{
	return this->cruiseAltitude;
}

double Aircraft::getClimbSpeed()
{
	return this->climbSpeed;
}

double Aircraft::getWingspan()
{
	return this->wingspan;
}

double Aircraft::getFuselageLength()
{
	return this->fuselageLength;
}
