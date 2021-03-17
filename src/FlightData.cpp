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

void Flight::PrintAllData(Flight F, int CurrentHr, int CurrentMin)
{
	printf("%s Flight %d - %s\n", F.getAirline(), F.getFlightNumber(), F.getAircraftType());
	//printf("\t\tDeparts: %s (%f, %f) at %d:%d\n", DepSymbol, Lat, Lon, LocTimeHr, LocTimeMin); // char // double // double // int // int
	//printf("\t\tArrives: %s (%f, %f) at %d:%d\n", DstSymbol, Lat, Lon, DstTimeHr, DstTimeMin); // char // double // double // int // int
	//printf("\t\tCurrent location: (%f, %f)\n", CurrentLocLat, CurrentLocLon); // double // double
	//printf("\t\t\t\t%f miles from %s, %f miles to %s", DepDistance, DepSymbol, DstDistance, DstSymbol); // double // char // double // char
	//printf("\t\tCurrent Speed: %f MPH\n", CurrentSpeed);
	//printf("\t\tCurrent Altitude: %f feet\n", CurrentAltitude);
}

void Flight::PrintDeparture(City C, Flight F, int CurrentHr, int CurrentMin)
{
	printf("now departing: %s flight %d, %s\n", F.getAirline(), F.getFlightNumber(), F.getAircraftType());
	cout << F.getArriveCity();
	vector<City> temp = C.ReturnCityVector();
	char tempDepCity[128] = {}; char tempArrCity[128] = {};
	char tempDepStat[128] = {}; char tempArrStat[128] = {};
	for (auto &it : temp)
	{
		if (strcmp(it.getSymbol(), F.getDepartCity()))	// if the symbol is equal to the departure city symbol
		{
			strcpy(tempDepCity, it.getName());
			strcpy(tempDepStat, it.getState());
			break;
		}
	}
	for (auto &it : temp)
	{
		if (strcmp(it.getSymbol(), F.getArriveCity()))
		{
			strcpy(tempArrCity, it.getName());
			strcpy(tempArrStat, it.getState());
			break;
		}
	}
	printf("\t\tfrom %s, %s\n", tempDepCity, tempDepStat); // HSV -> Alabama
	printf("\t\ten route to %s, %s\n", tempArrCity, tempArrStat);

	//printf("\t\tfrom %s, %s\n", F.getDepartCity(), C.ReturnState(F.getDepartCity())); // HSV -> Alabama
	//printf("\t\ten route to %s, %s\n", F.getArriveCity(), C.ReturnState(F.getArriveCity()));
	//printf("\t\testimated time of arrival: %d:%d", "call", "time calculation\n");
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
