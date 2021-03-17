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


Flight::Flight(char *al, char *plane, int flNum, char *depCity, int depHr, int depMin, char *dstCity)
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

void Flight::PrintAllData(int CurrentHr, int CurrentMin)
{
	//printf("%s Flight %d - %s\n", Airline, FlightNum, Plane);
	//printf("        Departs: %s (%f, %f) at %d:%d\n", DepSymbol, Lat, Lon, LocTimeHr, LocTimeMin); // char // double // double // int // int
	//printf("        Arrives: %s (%f, %f) at %d:%d\n", DstSymbol, Lat, Lon, DstTimeHr, DstTimeMin); // char // double // double // int // int
	//printf("        Current location: (%f, %f)\n", CurrentLocLat, CurrentLocLon); // double // double
	//printf("                  %f miles from %s, %f miles to %s", DepDistance, DepSymbol, DstDistance, DstSymbol); // double // char // double // char
	//printf("        Current Speed: %f MPH\n", CurrentSpeed);
	//printf("        Current Altitude: %f feet\n", CurrentAltitude);
}

void Flight::PrintDeparture(Flight F, int CurrentHr, int CurrentMin)
{
	printf("now departing: %s flight %d, %s\n", F.getAirline(), F.getFlightNumber(), F.getAircraftType());
	printf("                 from %s, %s\n", F.getDepartCity(), "city-state");
	printf("                 en route to %s, %s\n", F.getArriveCity(), "city-state");
	//printf("                 estimated time of arrival: %d:%d", "call", "time calculation\n");
}

void Flight::PrintArrival(int CurrentHr, int CurrentMin)
{
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("Now arriving: %s Flight %d, %s\n", airline, flightNumber, aircraftType);
	printf("                 at %s, %s\n", departCity, "dststatename");
	printf("                 from %s, %s\n", arriveCity, "depstatename");
	//printf("Current clock time: %d:%d\n", CurrentHr, CurrentMin);
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
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
