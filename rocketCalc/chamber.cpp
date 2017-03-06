#include <iostream>
#include <stdlib>
#include <cmath>

int main(int argc , char  *argv[]) {

  //meters
  double ChamberDiameter = strtod(argv[1],NULL);
  //psi
  double ChamberPressure = strtod(argv[2],NULL);
  
  std::cout << "convergentChamberAngle() :" << convergentChamberAngle()  << "\n";
  std::cout << "divergentChamberAngle() :" << divergentChamberAngle()  << "\n";
  std::cout << "nozzleThroatCrossArea() :" << nozzleThroatCrossArea()  << "\n";
  std::cout << "nozzleThroatDiameter() :" << nozzleThroatDiameter()  << "\n";
  std::cout << "chamberCrossArea()  :" << chamberCrossArea()   << "\n";
  std::cout << "chamberDiameter() :" << chamberDiameter()  << "\n";
  std::cout << "nozzleTemperature() :" << nozzleTemperature()  << "\n";
  std::cout << "chamberTemperature() :" << chamberTemperature()  << "\n";
  std::cout << "gamma() :" << gamma()  << "\n";
  
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

//ChamberPressure input is in psi, converted to pascals
double nozzlePressure() {
  return 6894.75729*(ChamberPressure*pow((1 + (gamma() - 1) / 2 ), -1 * gamma()/(gamma()-1)));
}

double chamberTemperature() {
  return 2.321*pow(10,-8)*pow(ChamberPressure,3) - 1.955*pow(10,-4)*pow(ChamberPressure,2) + 0.575*ChamberPressure + 3027.817;
}

double gamma() {
 return -6.988*pow(10,-13)*pow(ChamberPressure,3) + 6.032*pow(10,-9)*pow(ChamberPressure,2) - 1.823*pow(10,-5)*(ChamberPressure)+ 1.215; 
}




