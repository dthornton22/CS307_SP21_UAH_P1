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

}

void Simulation::initializeSimulation()
{

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
