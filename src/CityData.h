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
		string name;						// 
		string state;						// 
		float latitude;						// 
		float longitude;					// 

	public:
		City(); 							// Default constructor
		~City(); 							// Destructor
		void readData(string infile);		//
		int calcDistance(int flightnum);	//
};

#endif
