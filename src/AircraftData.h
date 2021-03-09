// ****************************************
// Program Title: Project1
// Project File: AircraftData.h
// Name: David Thornton
// Course Section: CS-307, SP 2021
// Due Date: 03/14/2021
// ****************************************
#include <string>
#ifndef AIRCRAFT_H
#define AIRCRAFT_H

using namespace std;

class Aircraft
{
	private:
		string make;						// 
		string model;						// 
		int cruiseSpeed;					// 
		int cruiseAltitude;					// 
		int climbSpeed;						// 
		int wingspan;						// 
		int fuselageLength;					// 

	public:
		Aircraft(); 						// Default constructor
		~Aircraft(); 						// Destructor
		void readData(string infile);		//					
};

#endif
