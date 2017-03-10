// Contains functions for calculating the flow of propellent (oxidizer and fuel)
//

#include<iostream>

void propellentFlowCall();


// returns the flow of fuel in units of kilograms/second
double fuelMassFlow();

// returns the flow of fuel in units of lb/second
double fuelWeightFlow();

// returns the flow of fuel in units of liters/second
double fuelVolumeFlow();

// returns the flow of oxidizer in units of kilograms/second
double oxidizerMassFlow();

// returns the flow of oxidizer in units of lb/second
double oxidizerWeightFlow();

// returns the flow of oxidizer in units of liters/second
double oxidizerVolumeFlow();

// returns the flow of total propellent (oxidizer + fuel) in units of kilograms/second
double propellentMassFlow();

// returns the flow of total propellent in units of lb/second
double propellentWeightFlow();

// returns the flow of total propellent (oxidizer + fuel) in units of liters/second
double propellentVolumeFlow();

// returns the density of propellant at the nozzle in units of kilograms/liter
double propellentDensity();

// returns the average molecular weight of propellent in units of g per
double propellentMolecularWeight();


double propellentGasConstant();
