//========================================================
// CityDataParser.h
// Interface file for the city data parser class.
//
// Authors: Dr. Rick Coleman, Dr. Jacob Hauenstein
// Date: January 2021
//========================================================
#ifndef CITYDATAPARSER_H
#define CITYDATAPARSER_H

#include <fstream>

using namespace std;

class CityDataParser
{
	private:
		int m_iCityCount;
		char m_sDataFile[32];
		bool m_bDataFileOK;
		fstream	*inFile;

	public:
		CityDataParser();					// Constructor
		~CityDataParser();					// Destructor
		void InitCityData(const char *dataFile);	// Read all data from the data file
		int getCityCount();
		bool getCityData(char *name, char *state, char *symbol, double *lat, double *lon);
		void getCitySymbolsArray(char ***array);
		void getDistTable(double **array);
		bool getNextLine(char *buffer, int n);

};

#endif
