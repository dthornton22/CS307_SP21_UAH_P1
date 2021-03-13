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
		string name{"empty"};				// 
		string state{"empty"};				// 
		float latitude{0};					// 
		float longitude{0};					// 

	public:
		City(); 							// Default constructor
		~City(); 							// Destructor
		void readData(string infile);		// 
		int calcDistance(int flightnum);	// 

		void setName(string param);			// 
		void setState(string param);		// 
		void setLatitude(float param);		// 
		void setLongitude(float param);		// 

		string getName();					// 
		string getState();					// 
		float getLatitude();				// 
		float getLongitude();				// 
};

#endif
