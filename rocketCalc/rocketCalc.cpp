// Rocket Value Calculator
// formulas taken from sites found with google
// No first hand experimental data was used

#include<iostream>

#include "helpers.h"


using namespace std;



int main() {
	cout<<" Welcome to the Rocket Value Calculator.\n This program was designed to avoid calculation errors and make life easier in general\n";
		
	double gamma = getValueFromStdIn("specific heat ratio (gamma)");
	double chamberPressure = getValueFromStdIn("mixture ratio");

	cout<<gamma<<" and "<<chamberPressure;	

	return 0;
}









