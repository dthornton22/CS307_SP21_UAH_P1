// ****************************************
// Program Title: Project1
// Project File: CityData.h
// Name: David Thornton
// Course Section: CS-307, SP 2021
// Due Date: 03/14/2021
// ****************************************
#include <string>
#ifndef CITY_H
#define CITY_H

using namespace std;

class City
{
	private:
		char* name{};
		char* state{};
		char* symbol{};
		double latitude{0};
		double longitude{0};
		int cityCount{0};

	public:
		City(); 							// Default constructor
		~City(); 							// Destructor
		void readData(string infile);		// 
		int calcDistance(int flightnum);	// 

		// Set functions
		void setName(char* param);
		void setState(char* param);
		void setLatitude(double param);
		void setLongitude(double param);

		// Get functions
		char* getName();
		char* getState();
		char* getSymbol();
		double getLatitude();
		double getLongitude();
};

#endif
