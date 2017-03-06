#include <iostream>
#include <cmath>

int main() {

  return 0;

}


//from website
double convergentChamberAngle() {
  return 60.0;
}

//from website
double divergentChamberAngle() {
  return 15.0;
}

//from cdiameter.h
double nozzleThroatCrossArea() {
  return getNozzleArea();
}

//from cdiameter.h
double nozzleThroatDiameter() {
  return getNozzleDiameter();
}


//uses gamma and chamber temperature
double nozzleTemperature() {
  return chamberTemperature()*( 1 / ( 1 + ( gamma() - 1) / 2 ) );
}

double nozzlePressure() {
  return chamberPressure()*pow((1 + (gamma() - 1) / 2 ), -1 * gamma()/(gamma()-1));
}




