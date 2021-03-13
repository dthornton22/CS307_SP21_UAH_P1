// ****************************************
// Program Title: Project1
// Project File: FlightData.h
// Name: David Thornton
// Course Section: CS-307, SP 2021
// Due Date: 03/14/2021
// ****************************************
#include <string>
#ifndef SIMULATION_H
#define SIMULATION_H

using namespace std;

class Flight
{
	private:
		int flightNumber{0};				// 
		int departTime{0};					// 
		string airline{"empty"};			// 
		string aircraftType{"empty"};		// 
		string departCity{"empty"};			// 
		string arriveCity{"empty"};			// 

	public:
		Flight(); 							// Default constructor
		~Flight(); 							// Destructor
		void readData(string infile);		// 

		void setFlightNumber(int param);	// 
		void setDepartTime(int param);		// 
		void setAirline(string param);		// 
		void setAircraftType(string param);	// 
		void setDepartCity(string param);	// 
		void setArriveCity(string param);	// 

		int getFlightNumber();				// 
		int getDepartTime();				// 
		string getAirline();				// 
		string getAircraftType();			// 
		string getDepartCity();				// 
		string getArriveCity();				// 
};

#endif
