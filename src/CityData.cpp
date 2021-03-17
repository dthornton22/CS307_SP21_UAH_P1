// ****************************************
// Program Title: Project1
// Project File: CityData.cpp
// Name: David Thornton
// Course: CS-307
// Due Date: 03/16/2021
// ****************************************
#include "CityData.h"
#pragma warning(disable : 4996)

City::City()
{
}

City::City(char* cityName, char* stateName, char* symbol, double lat, double lon)
{
	strcpy(name, cityName);
	strcpy(state, stateName);
	strcpy(sym, symbol);
	this->setLatitude(lat);
	this->setLongitude(lon);
}

City::~City()
{
}

void City::readData(char* infile)
{
	CityDataParser* ParseCity = new CityDataParser();
	ParseCity->InitCityData(infile);
	int CityCount = ParseCity->getCityCount();
	for (int i = 0; i < CityCount; i++)	// iterate through all cities collecting data
	{
		ParseCity->getCityData(name, state, sym, &latitude, &longitude);
		City NewCity(name, state, sym, latitude, longitude);
		CityList.push_back(NewCity);
	}
	double* distances;
	char** symbols;
	ParseCity->getCitySymbolsArray(&symbols);				// Get the city Symbols
	ParseCity->getDistTable(&distances);					// Get the distance table
}

vector<City> City::ReturnCityVector()
{
	return this->CityList;
}

double City::calcDistance(char depCity, char arrCity)
{
	return 0;
}

void City::setSymbol(char param)
{
	*this->sym = param;
}

void City::setName(char param)
{
	*this->name = param;
}

void City::setState(char param)
{
	*this->state = param;
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

char* City::getSymbol()
{
	return this->sym;
}

char* City::getState()
{
	return this->state;
}

double City::getLatitude()
{
	return this->latitude;
}

double City::getLongitude()
{
	return this->longitude;
}
