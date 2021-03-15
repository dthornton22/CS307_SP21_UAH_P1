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
		char* make{};
		char* model{};
		int cruiseSpeed{0};
		int cruiseAltitude{0};
		int climbSpeed{0};
		int wingspan{0};
		int fuselageLength{0};

	public:
		Aircraft(); 						// Default constructor
		~Aircraft(); 						// Destructor
		void readData();					// 	

		// Set functions
		void setMake(char* param);
		void setModel(char* param);
		void setCruiseSpeed(int param);
		void setCruiseAltitude(int param);
		void setClimbSpeed(int param);
		void setWingspan(int param);
		void setFuselageLength(int param);

		// Get functions
		char* getMake();
		char* getModel();
		int getCruiseSpeed();
		int getCruiseAltitude();
		int getClimbSpeed();
		int getWingspan();
		int getFuselageLength();
};

#endif
