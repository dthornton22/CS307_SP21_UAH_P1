//========================================================
// FlightDataParser.h
// Interface file for the flight data parser class.
//
// Authors: Dr. Rick Coleman, Dr. Jacob Hauenstein
// Date: January 2021
//========================================================
#ifndef FLIGHTDATAPARSER_H
#define FLIGHTDATAPARSER_H

#include "fstream"

using namespace std;

class FlightDataParser
{
	private:
		char m_sFlightDataFile[32];				// Name of the flight data file
		int  m_iStartHour;						// Hour the scenario starts (24 hr clock)
		int  m_iStartMin;						// Minute the scenario starts
		int  m_iAircraftCount;					// Number of aircraft types
		int  m_iFlightCount;					// Number of flights 
		bool m_bDataFileOK;						// Flag we have a good data file
		fstream	*inFile;

	public:
		FlightDataParser();						// Default constructor
		~FlightDataParser();					// Destructor
		void InitFlightData(const char *dataFile);	// Init the flight data
		void getStartTime(int *hr, int *min);	// Get the scenario start hour and minute
		int getAircraftCount();					// Get the number of aircraft types
		int getFlightCount();					// Get the number of flights
		bool getAircraftData(char *make, char *desc,
			double *roc, double *wngs, double *len,
			double *cs, double *ca);			// Get all data on an aircraft
		bool getFlightData(char *airline, char *plane,
			int *flNum, char *departCity, int *depHr,
			int *depMin, char *destCity);		// Get all data on a flight
		bool getNextLine(char *buffer, int n);
};

#endif
