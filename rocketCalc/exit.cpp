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
  return (nozzleThroatCrossArea()/exitMach() ) * pow ( (1+exitMach()*exitMach()*(gamma()-1)/2)/((gamma()+1)/2), (gamma()+1)/(2*gamma()-2));
}

// returns the diameter of the exit in units of meters
double exitDiameter() {
  return pow((exitArea()*4/3.14),0.5);
}

// returns the mach number of the exhaust at the exit
double exitMach() {
  return pow( ( 2 / ( gamma() - 1 ) ) * pow ( ChamberPressure / 14.70 , ( gamma() - 1 )
  / gamma() ) - 1, 0.5 );
}

// returns the velocity of the exiting gas in units of meters/second
double exitGasVelocity() {
  return exitMach()*343.29;
}

// returns the mean temperature for the exiting exhaust in degrees kelvin
double exitGasTemperature() {
  return pow(exitGasVelocity(),2)*propellentMolecularWeight()/(3*8.3144621*1000) ;
}

// returns the pressure at the exit in Pascals
double exitPressure() {
  return nozzleThroatPressure()*pow((1 + pow(exitMach(),2)*(gamma()-1)/2)
    ,(-gamma()/(gamma()-1))) ;
}

// returns the ratio between exit cross-sectional area and nozzle throat cross-sectional area
double expansionRatio() {
  return exitArea()/nozzleThroatCrossArea();
}

 
