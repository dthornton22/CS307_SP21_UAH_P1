//========================================================
// FlightDataParser.cpp
// Implementation file for the flight data parser class.
//
// Authors: Dr. Rick Coleman, Dr. Jacob Hauenstein
// Date: January 2021
//========================================================
#pragma warning(disable : 4996)

#include "FlightDataParser.h"
#include "string.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

//------------------------------------------
// Default constructor
//------------------------------------------
FlightDataParser::FlightDataParser()
{
	m_iStartHour = 0;
	m_iStartMin = 0;
	m_iAircraftCount = 0;
	m_iFlightCount = 0;
	m_bDataFileOK = false;
}

//------------------------------------------
// Destructor
//------------------------------------------
FlightDataParser::~FlightDataParser()
{
}

//------------------------------------------
// Init the flight data
//------------------------------------------
void FlightDataParser::InitFlightData(const char *dataFile)
{
	// Save the name of the data file
	strcpy(m_sFlightDataFile, dataFile);
	// Try to open the file
	inFile = new fstream();
	inFile->open(m_sFlightDataFile, fstream::in); // Open the data file
	if(!inFile->is_open())
	{
		cout << "Failed to open the Flight Data file.\nProgram terminating...\n";
		exit(0);
	}
	m_bDataFileOK = true; // flag the data file is good
	// Read and count the number of planes types, flights, and get
	//		the start hour and minute.
	char line[128];
	while(getNextLine(line, 127))
	{
		if(strcmp(line, "<STARTTIME>") == 0)
		{
			bool done = false;
			while(!done)
			{
				getNextLine(line, 127); // Read the next line
				if(strcmp(line, "<HOUR>") == 0)
				{
					getNextLine(line, 127); // Get hours
					m_iStartHour = atoi(line); // Convert string to int
				}
				else if(strcmp(line, "<MINUTE>") == 0)
				{
					getNextLine(line, 127); // Get MINUTES
					m_iStartMin = atoi(line); // Convert string to int
					done = true; // Flag we are done getting time
				}
			}
		}
		else if(strcmp(line, "<PLANE>") == 0)
		{
			m_iAircraftCount++;	// Count all planes
		}
		else if(strcmp(line, "<FLIGHT>") == 0)
		{
			m_iFlightCount++;	// Count all FLIGHTS
		}
	}
	inFile->close();
	delete inFile;
}

//------------------------------------------
// Get the scenario start hour and minute
// Args: hr - Pointer to an int to hold the
//				scenario start hour.
//		 min - Pointer to an int to hold the
//				scenario start minute.
//------------------------------------------
void FlightDataParser::getStartTime(int *hr, int *min)
{
	*hr = m_iStartHour;
	*min = m_iStartMin;
}

//------------------------------------------
// Get the number of aircraft types
//------------------------------------------
int FlightDataParser::getAircraftCount()
{
	return m_iAircraftCount;
}

//------------------------------------------
// Get the number of flights
//------------------------------------------
int FlightDataParser::getFlightCount()
{
	return m_iFlightCount;
}

//---------------------------------------------------
// Get all data on an aircraft
// Args: t - An enumerated data type identifying
//				the aircraft type. See
//				AircraftTypes.h 
//		 make - Pointer to a character array to hold
//					the name of the plane make, 
//					example: Boeing.
//		 desc - Pointer to a character array to hold
//					the description of the aircraft
//		 roc - Pointer to a double to hold the rate
//					of climb in feet per minute.
//		 wngs - Pointer to a double to hold the wing
//					span in feet.
//		 len - Pointer to a double to hold the 
//					fuselage length in feet.
//		 cs - Pointer to a double to hold the cruise
//					speed in flight.
//		 ca - Pointer to a double to hold the cruise
//					altitude.
//---------------------------------------------------
bool FlightDataParser::getAircraftData(char *make, char *desc,
	double *roc, double *wngs, double *len,
	double *cs, double *ca)
{
	static int nextPlaneIdx = 0; // Index of the next plane to read
	int planeIdx = 0;	// current count of planes

	// Have we already read all plane data?
	if(nextPlaneIdx >= m_iAircraftCount) return false;

	// Try to open the file
	inFile = new fstream();
	inFile->open(m_sFlightDataFile, fstream::in); // Open the data file
	if(!inFile->is_open())
	{
		cout << "Failed to open the Flight Data file.\nProgram terminating...\n";
		exit(0);
	}
	char line[128];
	// Find the next plane
	while(getNextLine(line, 127))
	{
		if(strcmp(line, "<PLANE>") == 0)
		{
			// Found a plane check the index
			if(planeIdx == nextPlaneIdx) 
			{
				bool done = false;
				while(!done)
				{
					getNextLine(line, 127); // Read the next line
					if(strcmp(line, "<MAKE>") == 0)
					{
						getNextLine(line, 127);
						strcpy(make, line); // Save the aircraft make
					}
					else if(strcmp(line, "<DESCRIPTION>") == 0)
					{
						getNextLine(line, 127);
						strcpy(desc, line); // Save the aircraft description
					}
					else if(strcmp(line, "<RATEOFCLIMB>") == 0)
					{
						getNextLine(line, 127);
						*roc = atof(line); // Save rate of climb
					}
					else if(strcmp(line, "<WINGSPAN>") == 0)
					{
						getNextLine(line, 127);
						*wngs = atof(line); // Save wing span in feet
					}
					else if(strcmp(line, "<LENGTH>") == 0)
					{
						getNextLine(line, 127);
						*len = atof(line); // Save fuselage length in feet
					}
					else if(strcmp(line, "<CRUISESPEED>") == 0)
					{
						getNextLine(line, 127);
						*cs = atof(line); // Save cruise speed in Miles Per Hour
					}
					else if(strcmp(line, "<CRUISEALTITUDE>") == 0)
					{
						getNextLine(line, 127);
						*ca = atof(line); // Save cruise altitude in feet
					}
					else if(strcmp(line, "</PLANE>") == 0)
					{
						done = true; // Flag done reading data for this plane
						nextPlaneIdx++; // Index for next call
						inFile->close();
						delete inFile;
						return true;
					}
				} // end while not done
			} // end if this is the index we want
			planeIdx++; // increment count of planes
		} // end if this is a PLANE tag
	} // end while
	return false;
}

//---------------------------------------------------
// Get all data on a flight
// Args: airline - Pointer to a character array to
//					hold the name of the airline.
//		 plane - Pointer to a character array to hold
//					the name of the type of aircraft.
//		 flNum - Pointer to an int to hold the flight
//					number.
//		 departCity - Pointer to a character array to
//					hold the 3-letter symbol for the
//					flight departure city.
//		 depHr - Pointer to an int to hold the 
//					departure hour.
//		 depMin - Pointer to an int to hold the 
//					departure minute.
//		 destCity - Pointer to a character array to
//					hold the 3-letter symbol for the
//					flight destination city.
// Returns: True if the data are valid.  False when
//			all flight data has been read.
//---------------------------------------------------
bool FlightDataParser::getFlightData(char *airline, char *plane,
	int *flNum, char *departCity, int *depHr,
	int *depMin, char *destCity)
{
	static int nextFlightIdx = 0;
	int flightIdx = 0;
		
	// Have we already read all plane data?
	if(nextFlightIdx >= m_iFlightCount) return false;


	// Try to open the file
	inFile = new fstream();
	inFile->open(m_sFlightDataFile, fstream::in); // Open the data file
	if(!inFile->is_open())
	{
		cout << "Failed to open the Flight Data file.\nProgram terminating...\n";
		exit(0);
	}
	char line[128];
	// Find the next flight
	while(getNextLine(line, 127))
	{
		if(strcmp(line, "<FLIGHT>") == 0)
		{
			// Found a plane check the index
			if(flightIdx == nextFlightIdx) 
			{
				bool done = false;
				while(!done)
				{
					getNextLine(line, 127); // Read the next line
					if(strcmp(line, "<AIRLINE>") == 0)
					{
						getNextLine(line, 127);
						strcpy(airline, line); // Save the airline name
					}
					else if(strcmp(line, "<PLANETYPE>") == 0)
					{
						getNextLine(line, 127);
						strcpy(plane, line); // Save the plane type
					}
					else if(strcmp(line, "<FLIGHTNUMBER>") == 0)
					{
						getNextLine(line, 127);
						*flNum = atoi(line); // Save flight number
					}
					else if(strcmp(line, "<DEPARTSFROM>") == 0)
					{
						getNextLine(line, 127);
						strcpy(departCity, line); // Save departure city symbol
					}
					else if(strcmp(line, "<DEPARTURETIME>") == 0)
					{
						bool done2 = false;
						while(!done2)
						{
							getNextLine(line, 127); // Read the next line
							if(strcmp(line, "<HOUR>") == 0)
							{
								getNextLine(line, 127); // Get hour
								*depHr = atoi(line); // Convert string to int
							}
							else if(strcmp(line, "<MINUTE>") == 0)
							{
								getNextLine(line, 127); // Get minute
								*depMin = atoi(line); // Convert string to int
							}
							else if(strcmp(line, "</DEPARTURETIME>") == 0)
							{
								done2 = true; // Flag we are done getting time
							}
						}
					}
					else if(strcmp(line, "<DESTINATION>") == 0)
					{
						getNextLine(line, 127);
						strcpy(destCity, line); // Save destination city symbol
					}
					else if(strcmp(line, "</FLIGHT>") == 0)
					{
						done = true; // Flag done reading data for this FLIGHT
						nextFlightIdx++; // Index for next call
						inFile->close();
						delete inFile;
						return true;
					}
				} // end while not done
			} // end if this is the index we want
			flightIdx++; // increment count of flights
		} // end if this is a FLIGHT tag
	} // end while
	return false;
}

//------------------------------------------------
// Function: getNextLine()
// Purpose: Reads lines from a file and places
//   them in buffer, removing any leading white
//   space.  Skips blank lines. Ignors comment
//   lines starting with <!-- and ending with -->
//   
// Args:  buffer -- char array to read line into.
//        n -- length of buffer.
// Returns: True if a line was successfully read,
//    false if the end of file was encountered.
// Notes: Function provided by instructor.
//------------------------------------------------
bool FlightDataParser::getNextLine(char *buffer, int n)
{
    bool    done = false;
	char    tempBuf[128];
	char	*temp;
    while(!done)
    {
        inFile->getline(tempBuf, n); // Read a line from the file

        if(inFile->good())          // If a line was successfully read check it
        {
           if(strlen(tempBuf) == 0)     // Skip any blank lines
               continue;
		   else if(strncmp(tempBuf, "<!--", 4) == 0) // Skip comment lines
			   continue;
           else done = true;    // Got a valid data line so return with this line
        }
        else
        {
            strcpy(buffer, "");  // Clear the buffer array
            return false;        // Flag end of file
        }
    } // end while
	// Remove white space from end of string
	temp = &tempBuf[strlen(tempBuf)]; // point to closing \0
	temp--; // back up 1 space
	while(isspace(*temp))
	{
		*temp = '\0'; // Make it another NULL terminator
		temp--;  // Back up 1 char
	}
	// Remove white space from front of string
	temp = tempBuf;
	while(isspace(*temp)) temp++; // Skip leading white space
	// Copy remainder of string into the buffer
	strcpy(buffer, temp);
    return true;  // Flag a successful read
}
