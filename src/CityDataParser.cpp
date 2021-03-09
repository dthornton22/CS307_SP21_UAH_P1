//========================================================
// CityDataParser.cpp
// Implementation file for the city data parser class.
//
// Authors: Dr. Rick Coleman, Dr. Jacob Hauenstein
// Date: January 2021
//========================================================
#pragma warning(disable : 4996)

#include "CityDataParser.h"
#include "iostream"
#include "cstdlib"	// for atof()
#include "ctype.h"

using namespace std;

//----------------------------------------
// Private constructor
//----------------------------------------
CityDataParser::CityDataParser()
{
	m_iCityCount = 0;
	m_bDataFileOK = false;
}

//----------------------------------------
// Destructor
//----------------------------------------
CityDataParser::~CityDataParser()
{
}

//----------------------------------------
// Initialize data from the data file
//----------------------------------------
void CityDataParser::InitCityData(const char *dataFile)
{
	strcpy(m_sDataFile, dataFile);	// Save the data file
	// Try to open the file
	inFile = new fstream();
	inFile->open(dataFile, fstream::in); // Open the data file
	if(!inFile->is_open())
	{
		cout << "Failed to open the City Data file.\nProgram terminating...\n";
		exit(0);
	}
	m_bDataFileOK = true; // flag the data file is good
	// Read and count the number of cities
	char line[128];
	while(getNextLine(line, 127))
	{
		if(strcmp(line, "<CITY>") == 0)
		{
			m_iCityCount++;	// Count all cities
		}
	}
	inFile->close();
	delete inFile;
}

//----------------------------------------
// Return the count of cities
//----------------------------------------
int CityDataParser::getCityCount()
{
	return m_iCityCount;
}

//--------------------------------------------------------------
// Read information on next city
// Args:  name - Pointer to a char array to hold city name
//		  state - Pointer to a char array to hold state name
//		  symbol - Pointer to a char array to hold city
//					symbol.  This is a 3-letter symbol for
//				    all cities so a 4-char array is adequate.
//		  lat - pointer to a double to hold the city latitude
//		  lon - pointer to a double to hold the city longitude
// Returns FALSE if all cities have been read.
//--------------------------------------------------------------
bool CityDataParser::getCityData(char *name, char *state, char *symbol, double *lat, double *lon)
{
	char line[128];
	static int nextCityIdx = 0;
	int thisCount = 0;
	if(nextCityIdx >= m_iCityCount)
		return false; // All cities have been read

	// Open the data file and search for the city
	inFile = new fstream();
	inFile->open(m_sDataFile, fstream::in); // Open the data file
	if(!inFile->is_open())
	{
		cout << "Failed to open the City Data file.\nProgram terminating...\n";
		exit(0);
	}

	while(getNextLine(line, 127))
	{
		if(strcmp(line, "<CITY>") == 0)
		{
			if(thisCount == nextCityIdx) // Want this one
			{
				while(strcmp(line, "</CITY>") != 0)
				{
					getNextLine(line, 127); // Read a line
					if(strcmp(line, "<CITYNAME>") == 0)
					{
						getNextLine(line, 127); // Read city name
						strcpy(name, line);
					}
					else if(strcmp(line, "<STATE>") == 0)
					{
						getNextLine(line, 127); // Read state name
						strcpy(state, line);
					}
					else if(strcmp(line, "<SYMBOL>") == 0)
					{
						getNextLine(line, 127); // Read city symbol
						strcpy(symbol, line);
					}
					else if(strcmp(line, "<LATITUDE>") == 0)
					{
						getNextLine(line, 127); // Read city symbol
						*lat = atof(line);
					}
					else if(strcmp(line, "<LONGITUDE>") == 0)
					{
						getNextLine(line, 127); // Read city symbol
						*lon = atof(line);
					}
				} // end while reading all city data
				inFile->close(); // close the file
				delete inFile;
				nextCityIdx++;
				return true;
			}
			else
			{
				thisCount++;	// Increment and check the next one
			}
		}
	}
	return false; // to avoid the compiler warning.
}

//----------------------------------------
// Build the array of city symbols.  These
//  will be in the same order as the rows
//  and columns in the distances array.
//
// Arg: Pointer a pointer to a pointer to
//      a character.  For example
//		char **m_sCitySymbols;
// How to call this function:
//     cdp->getCitySymbolsArray(&m_sCitySymbols)
// Upon return the pointer m_sCitySymbols will
//   point to a dynamically created array 
//   of pointers to character arrays, each
//   containing a 3 letter symbol for a
//   city.  The array of pointers will be
//   NULL terminated.
// To avoid memory leaks you must iterate
//   through the entire array of pointers
//   to char arrays and delete each array
//   then delete the array of pointers.
//----------------------------------------
void CityDataParser::getCitySymbolsArray(char ***array)
{
	// Dynamically create an array of pointers to characters
	*array = new char*[m_iCityCount + 1];
	// Dynamically create all of the 4 character arrays
	//  Remember: 4 chars because we need space for 3 char symbol plus NULL terminator
	for(int i=0; i<m_iCityCount; i++)
	{
		(*array)[i] = new char[4];
	}
	(*array)[m_iCityCount] = NULL; // NULL terminate the array of pointers to char arrays

	// Open data file for reading
	inFile = new fstream();
	inFile->open(m_sDataFile, fstream::in); // Open the data file
	if(!inFile->is_open())
	{
		cout << "Failed to open the City Data file.\nProgram terminating...\n";
		exit(0);
	}
	// Read all the city symbols
	int nextIdx = 0;
	char line[128];

	while(getNextLine(line, 127))
	{
		if(strcmp(line, "<SYMBOL>") == 0)
		{
			getNextLine(line, 127); // Read the symbol
			strcpy((*array)[nextIdx], line);
			nextIdx++;
		}
	} // end while
	inFile->close();
	delete inFile;
}

//----------------------------------------
// Build the table of distances between
//  cities. This will be a dynamically
//  created 1-dimensional array of doubles
//  which, with appropriate index
//  calculations, can be treated as a 2-D
//  table.  The row and column order will
//  be the same as the symbols in the 
//  city symbols array.
//
// Arg: Pointer a pointer to a double.  
//      For example:
//		double *m_dDistTable;
// How to call this function:
//     cdp->getDistTable(&m_dDistTable)
// Upon return the pointer m_dDistTable will
//   point to a dynamically created array 
//   of doubles.
// To get a distance beteen cities do this:
//   1. Locate the departure city in the
//       symbols array and note its' index.
//   2. Locate the arrival city in the
//       symbols array and note its' index.
//   3. Use the departure as a row index.
//       and the arrival city as a column
//       index.
//   4. To find the real index into the
//       distances array use this formula:
//       double dist = m_dDistTable[(depCityIdx * numberOfCities) +
//            arrCityIdx];
//
// In your destructor to delete the array 
//    of doubles use this code:
//    delete[] m_dDistTable;
//----------------------------------------
void CityDataParser::getDistTable(double **array)
{
	char line[128];

	*array = new double[m_iCityCount * m_iCityCount];
	// Open the data file and search for the city
	inFile = new fstream();
	inFile->open(m_sDataFile, fstream::in); // Open the data file
	if(!inFile->is_open())
	{
		cout << "Failed to open the City Data file.\nProgram terminating...\n";
		exit(0);
	}

	int idx = 0;
	while(getNextLine(line, 127))
	{
		if(strcmp(line, "<ROWS>") == 0) // Look for start of the table
		{
			while(getNextLine(line, 127))
			{
				if(strcmp(line, "<DISTANCE>") == 0) // Got a distance
				{
					getNextLine(line, 127); // Read the distance line
					(*array)[idx] = atof(line);
					idx++;
				}
			}
		}
	}
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
bool CityDataParser::getNextLine(char *buffer, int n)
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
