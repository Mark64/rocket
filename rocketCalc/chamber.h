// Code for calculating values dealing with the nozzle
//

#include<iostream>

//Output all variables
void chamberCall();

// returns the angle of the convergent section of the chamber in units of degrees
double convergentChamberAngle();

// returns the angle of the divergent section of the chamber in units of degrees
double divergentChamberAngle();

// returns the cross sectional area at the nozzle throat in units of meters^2
double nozzleThroatCrossArea();

// returns the diameter of the nozzle throat in units of meters
double nozzleThroatDiameter();

// returns the cross area of the chamber in units of meters
double chamberCrossArea();

// returns the diameter of the chamber in units of meters
double chamberDiameter();

// returns the temperature of the exhaust at the nozzle in units of Kelvin
double nozzleTemperature();

// returns the pressure of the exhaust at the nozzle in units of Pascals
double nozzlePressure();

// returns the pressure of the exhaust at the chamber in units of Pascals
double chamberPressure();

// returns the temperature of the chamber in units of Kelvin
double chamberTemperature();

// returns the volume of the chamber (not including convergent) in units of meters^3
double chamberVolume();

// returns the volume of the chamber (not including convergent) in units of Liters
double chamberVolumeL();

// returns the thickness of the chamber in units of meters
double chamberThickness();

// returns the length of the chamber in units of meters
double chamberLength();

// returns the ratio of the chamber cross-sectional area to the nozzle throat crosss sectional area 
double contractionRatio();

// returns the specific heat ratio of products
double gamma();

// returns the optimal ratio of oxidizer to fuel
double mixtureRatio();

// user parameters for chamber diameter and pressure
//extern double ChamberDiameter, ChamberPressure;
