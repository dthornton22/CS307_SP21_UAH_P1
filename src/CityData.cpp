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
	City::readData();
}

City::~City()
{
	
}

void City::readData()
{
	CityDataParser* ParseCity = new CityDataParser();
	ParseCity->InitCityData("C:/Users/David Thornton/source/repos/CS307Project1/src/Data/CityData01.xml");
	vector<City> CityList;
	printf("Number of cities: %d\n", ParseCity->getCityCount()); // test
/*
	for (int i = 0; i < ParseCity->getCityCount(); i++)        // iterate through all cities collecting data
	{
		ParseCity->getCityData(name, state, symbol, &latitude, &longitude);
		//City newcity(*tempcityname, *tempstatename, *tempsymbol, templat, templon);
		//CityList.push_back(newcity);
		//newcity.printcitydata();
	}
	*/
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
