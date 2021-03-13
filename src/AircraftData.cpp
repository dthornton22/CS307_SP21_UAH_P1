// ****************************************
// Program Title: Project1
// Project File: AircraftData.cpp
// Name: David Thornton
// Course Section: CS-307, SP 2021
// Due Date: 03/14/2021
// ****************************************

#include "AircraftData.h"

Aircraft::Aircraft()
{
	
}

Aircraft::~Aircraft()
{
	
}

void Aircraft::readData(string infile)
{
	
}

void Aircraft::setMake(string param)
{
	this->make = param;
}

void Aircraft::setModel(string param)
{
	this->model = param;
}

void Aircraft::setCruiseSpeed(int param)
{
	this->cruiseAltitude = param;
}

void Aircraft::setCruiseAltitude(int param)
{
	this->cruiseAltitude = param;
}

void Aircraft::setClimbSpeed(int param)
{
	this->climbSpeed = param;
}

void Aircraft::setWingspan(int param)
{
	this->wingspan = param;
}

void Aircraft::setFuselageLength(int param)
{
	this->fuselageLength = param;
}

string Aircraft::getMake()
{
	return this->make;
}

string Aircraft::getModel()
{
	return this->model;
}

int Aircraft::getCruiseSpeed()
{
	return this->cruiseSpeed;
}

int Aircraft::getCruiseAltitude()
{
	return this->cruiseAltitude;
}

int Aircraft::getClimbSpeed()
{
	return this->climbSpeed;
}

int Aircraft::getWingspan()
{
	return this->wingspan;
}

int Aircraft::getFuselageLength()
{
	return this->fuselageLength;
}
