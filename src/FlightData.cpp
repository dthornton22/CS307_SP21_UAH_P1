// ****************************************
// Program Title: Project1
// Project File: FlightData.cpp
// Name: David Thornton
// Course: CS-307
// Due Date: 03/16/2021
// ****************************************
#include "FlightData.h"
#pragma warning(disable : 4996)

Flight::Flight()
{
}

Flight::Flight(char* al, char* plane, int flNum, char* depCity, int depHr, int depMin, char* dstCity)
{
	strcpy(airline, al);
	strcpy(aircraftType, plane);
	this->flightNumber = flNum;
	strcpy(departCity, depCity);
	this->departTimeHr = depHr;
	this->departTimeMin = depMin;
	strcpy(arriveCity, dstCity);
}

Flight::~Flight()
{
}

void Flight::readData(char* infile)
{
	FlightDataParser* ParseFlight = new FlightDataParser();
	ParseFlight->InitFlightData(infile);
	const int FlightCount = ParseFlight->getFlightCount();
	for (int i = 0; i < FlightCount; i++)
	{
		ParseFlight->getFlightData(airline, aircraftType, &flightNumber, departCity, &departTimeHr, &departTimeMin, arriveCity);
		Flight* NewFlight = new Flight(airline, aircraftType, flightNumber, departCity, departTimeHr, departTimeMin, arriveCity);
		FlightList.push_back(*NewFlight);
	}
	ParseFlight->getStartTime(&StartHr, &StartMin);
}

vector<Flight> Flight::ReturnFlightVector()
{
	return this->FlightList;
}

void Flight::PrintAllData(Aircraft A, City C, Flight F, int CurrentHr, int CurrentMin)
{
	vector<Aircraft> AircraftData = A.ReturnAircraftList();
	vector<City> CityData = C.ReturnCityVector();
	double tempLat; double tempLon;
	printf("%s Flight %d - %s\n", F.getAirline(), F.getFlightNumber(), F.getAircraftType());
	for (auto& it : CityData)
	{
		if (strcmp(it.getSymbol(), F.getDepartCity()) == 0)
		{
			printf("\t\tDeparts: %s (%f, %f) at %d:%d\n", F.getDepartCity(), it.getLatitude(), it.getLongitude(), F.getDepartHour(), F.getDepartMin());
		}
	}

	for (auto& it : CityData)
	{
		if (strcmp(it.getSymbol(), F.getArriveCity()) == 0)
		{
			// DO THE TIME CALCULATION HERE!!!!!
			printf("\t\tArrives: %s (%f, %f) at %d:%d\n", F.getArriveCity(), it.getLatitude(), it.getLongitude(), F.getDepartHour(), F.getDepartMin());
		}
	}
	//printf("\t\tCurrent location: (%f, %f)\n", CurrentLocLat, CurrentLocLon); // double // double
	//printf("\t\t\t\t%f miles from %s, %f miles to %s", DepDistance, DepSymbol, DstDistance, DstSymbol); // double // char // double // char
	for (auto& it : AircraftData)
	{
		if (strcmp(F.getAircraftType(), it.getModel()) == 0)
		{
			printf("\t\tCurrent Speed: %f MPH\n", it.getCruiseSpeed());
		}
	}
	for (auto& it : AircraftData)
	{
		if (strcmp(F.getAircraftType(), it.getModel()) == 0)
		{
			printf("\t\tCurrent Speed: %f MPH\n", it.getCruiseAltitude());
		}
	}
}

void Flight::PrintDeparture(City C, Flight F, int CurrentHr, int CurrentMin)
{
	printf("now departing: %s flight %d, %s\n", F.getAirline(), F.getFlightNumber(), F.getAircraftType());
	vector<City> temp = C.ReturnCityVector();
	for (auto& it : temp)
	{
		if (strcmp(it.getSymbol(), F.getDepartCity()) == 0)	// if the symbol is equal to the departure city symbol
		{
			printf("\t\tfrom %s, %s\n", it.getName(), it.getState());
		}
	}
	for (auto& it : temp)
	{
		if (strcmp(it.getSymbol(), F.getArriveCity()) == 0)
		{
			printf("\t\ten route to %s, %s\n", it.getName(), it.getState());
		}
	}
}

void Flight::PrintArrival(City C, Flight F, int CurrentHr, int CurrentMin)
{
	//printf("Now arriving: %s Flight %d, %s\n", F.getAirline(), F.getFlightNumber(), F.getAircraftType());
	//printf("\t\tat %s, %s\n", F.getArriveCity(), *C.ReturnState(F.getArriveCity()));
	//printf("\t\tfrom %s, %s\n", F.getDepartCity(), *C.ReturnState(F.getDepartCity()));
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

int Flight::getStartMin()
{
	return this->StartMin;
}

int Flight::getStartHr()
{
	return this->StartHr;
}
