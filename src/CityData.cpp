// ****************************************
// Program Title: AircraftRapper
// Project File: CityData.cpp
// Name: Nolan Anderson
// Course: CS-307
// Due Date: 03/16/2021
// ****************************************
#include "CityData.h"

City::City(char name, char state, char symbol, double lat, double lon)
{
	this->setName(name);
	this->setState(state);
	this->setSymbol(symbol);
	this->latitude = lat;
	this->longitude = lon;
}

City::~City()
{
	
}

void City::readData()
{
	CityDataParser * ParseCity = new CityDataParser();
	ParseCity->InitCityData("../CityData01.xml");
	int CityCount = ParseCity->getCityCount();
	vector<City> CityList;
	for (int i = 0; i < CityCount; i++)        // iterate through all cities collecting data
	{
		ParseCity->getCityData(name , state, sym, &latitude, &longitude);
		City NewCity(*name, *state, *sym, latitude, longitude);
		CityList.push_back(NewCity);
	}
	ParseCity->getCitySymbolsArray(&symbols);				// Get the city Symbols
	ParseCity->getDistTable(&distances);					// Get the distance table
}

double City::calcDistance(char depCity, char arrCity)
{

	return 0;
}

void City::setSymbol(char param)
{
	this->sym[128] = param;
}

void City::setName(char param)
{
	this->name[128] = param;
}

void City::setState(char param)
{
	this->state[128] = param;
}

void City::setLatitude(double param)
{
	this->latitude = param;
}

void City::setLongitude(double param)
{
	this->longitude = param;
}

char City::getName()
{
	return this->name[128];
}

char City::getSymbol()
{
	return this->sym[128];
}

char City::getState()
{
	return this->state[128];
}

double City::getLatitude()
{
	return this->latitude;
}

double City::getLongitude()
{
	return this->longitude;
}
