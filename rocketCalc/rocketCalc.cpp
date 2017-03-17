// Rocket Value Calculator
// formulas taken from sites found with google
// No first hand experimental data was used

#include<iostream>
#include <stdlib.h>
#include <string> 
#include "helpers.h"


using namespace std;



int main() {
	cout<<" Welcome to the Rocket Value Calculator.\n
This program was designed to avoid calculation errors and make life easier in general\n\n";
	string fuel = getValueFromStdIn("Enter the fuel type(Gasoline, Kerosene, Hydrogen, JP-4, Alcohol): ");
	double chamberPressure = getValueFromStdIn("Enter the chamber pressure in PSI: ");
	double propelMach = getValueFromStdIn("Enter the exhaust mach: ");
	
		

	return 0;
}


//combustion reactions approximated








