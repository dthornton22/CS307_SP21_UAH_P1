// ****************************************
// Program Title: Project1
// Project File: CityData.cpp
// Name: David Thornton
// Course Section: CS-307, SP 2021
// Due Date: 03/14/2021
// ****************************************
#include "CityData.h"

City::City()
{
	
}

City::~City()
{
	
}

void City::readData(string infile)
{

}

int City::calcDistance(int flightnum)
{

	return 0;
}

void City::setName(string param)
{
	this->name = param;
}

void City::setState(string param)
{
	this->state = param;
}

void City::setLatitude(float param)
{
	this->latitude = param;
}

void City::setLongitude(float param)
{
	this->longitude = param;
}

string City::getName()
{
	return this->name;
}

string City::getState()
{
	return this->state;
}

float City::getLatitude()
{
	return this->latitude;
}

float City::getLongitude()
{
	return this->longitude;
}
