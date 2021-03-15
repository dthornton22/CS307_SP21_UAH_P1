// ****************************************
// Program Title: Project1
// Project File: CityData.cpp
// Name: David Thornton
// Course Section: CS-307, SP 2021
// Due Date: 03/14/2021
// ****************************************
#include "CityData.h"
#include "CityDataParser.h"

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

void City::setName(char* param)
{
	this->name = param;
}

void City::setState(char* param)
{
	this->state = param;
}

void City::setLatitude(double param)
{
	this->latitude = param;
}

void City::setLongitude(double param)
{
	this->longitude = param;
}

char* City::getName()
{
	return this->name;
}

char* City::getState()
{
	return this->state;
}

char* City::getSymbol()
{
	return this->symbol;
}
double City::getLatitude()
{
	return this->latitude;
}

double City::getLongitude()
{
	return this->longitude;
}
