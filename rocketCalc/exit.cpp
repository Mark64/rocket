#include <iostream>
#include "chamber.h"
#include "parameters.h"
#include "propellentFlow.h"
#include "exit.h"
#include <cmath>
using namespace std;

void exitCall() {
  cout << "Exit Area (m^2):" << exitArea() << "\n";
  cout << "Exit Diameter (m):" << exitDiameter() << "\n";
  cout << "Exit Mach :" << exitMach() << "\n";
  cout << "Exit Gas Velocity (m/s):" << exitGasVelocity() << "\n";
  cout << fixed << "Exit Gas Temperature (K):" << exitGasTemperature() << "\n";
  cout << "Exit Pressure  (Pa):" << exitPressure() << "\n";
  cout << "Expansion Ratio:" << expansionRatio() << "\n\n";
 }


// returns the area of the exit space for the thruster exhaust in units of meters^2
double exitArea() {
  double result = 0;
  if (ChamberPressure < 301)
    result = nozzleThroatCrossArea()*3.65;
  if (ChamberPressure > 301) 
    result = nozzleThroatCrossArea()*5.28;
  return result;
}

// returns the diameter of the exit in units of meters
double exitDiameter() {
  return pow((exitArea()*4/3.14),0.5);
}

// returns the mach number of the exhaust at the exit
double exitMach() {
  double result = 0;
  if (ChamberPressure < 301)
    result = 2.55;
  if (ChamberPressure > 301)
    result = 2.83;
  return result;
}

// returns the velocity of the exiting gas in units of meters/second
double exitGasVelocity() {
  return exitMach() * 343;
}

// returns the mean temperature for the exiting exhaust in degrees kelvin
double exitGasTemperature() {
  double result = 0;
  if (ChamberPressure < 301) 
    result = 0.606*chamberTemperature();
  if (ChamberPressure > 301)
    result = 0.55*chamberTemperature();
    return result;
}

// returns the pressure at the exit in Pascals
double exitPressure() {
  return 101325;

}

// returns the ratio between exit cross-sectional area and nozzle throat cross-sectional area
double expansionRatio() {
  return exitArea()/nozzleThroatCrossArea();
}

 
