// ****************************************
// Program Title: Project1
// Project File: Simulation.cpp
// Name: David Thornton
// Course Section: CS-307, SP 2021
// Due Date: 03/14/2021
// ****************************************
#include "Simulation.h"

Simulation::Simulation()
{

}

Simulation::~Simulation()
{
	
}

int Simulation::getFlightETA()
{
	return 0;
}

void Simulation::printReport()
{

}

void Simulation::runSimulation()
{
	// int timer = this->clockMult;
}

void Simulation::initializeSimulation()
{
	string temp = "";
	cout << "Please enter the name of your input (.txt) file: ";
	cin >> temp;
	cout << "Parsing data from " << temp << "..." << endl;
	char* infile = &temp[0];
}

void Simulation::setClockMult(int param)
{
	this->clockMult = param;
}

void Simulation::setInFile(string param)
{
	this->inFile = param;
}

int Simulation::getClockMult()
{
	return this->clockMult;
}

string Simulation::getInFile()
{
	return this->inFile;
}
