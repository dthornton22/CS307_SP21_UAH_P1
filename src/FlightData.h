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
		int flightNumber;					// 
		int departTime;						// 
		string airline;						// 
		string aircraftType;				// 
		string departCity;					// 
		string arriveCity;					// 

	public:
		Flight(); 							// Default constructor
		~Flight(); 							// Destructor
		void readData(string infile);		//

		void setFlightNumber();				//
		void setDepartTime();				//
		void setAirline();					//
		void setAircraftType();				//
		void setDepartCity();				//
		void setArriveCity();				//

		int getFlightNumber();				//
		int getDepartTime();				//
		string getAirline();				//
		string getAircraftType();			//
		string getDepartCity();				//
		string getArriveCity();				//
};

#endif
