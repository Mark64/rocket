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

double nozzleThroatCrossArea() {
  return chamberCrossArea()/3;
}

double nozzleThroatDiameter() {
  return pow(4*nozzleThroatCrossArea()/3.14159,0.5);
}

double chamberCrossArea() {
  return pow(ChamberDiameter/2,2)*3.1459;
}

double chamberDiameter() {
  return ChamberDiameter;  
}

//uses gamma and chamber temperature
double nozzleTemperature() {
  return chamberTemperature()*( 1 / ( 1 + ( gamma() - 1) / 2 ) );
}

double nozzlePressure() {
  return chamberPressure()*pow((1 + (gamma() - 1) / 2 ), -1 * gamma()/(gamma()-1));
}




