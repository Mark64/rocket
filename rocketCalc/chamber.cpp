#include "chamber.h"
#include "parameters.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>

//double ChamberDiameter = 0.09;
//double ChamberPressure = 440;

void chamberCall() {

  
  std::cout << "gamma:" << gamma()  << "\n";
  std::cout << "ratio:" << mixtureRatio() << "\n\n";
  std::cout << "convergentChamberAngle(deg):" << convergentChamberAngle()  << "\n";
  std::cout << "divergentChamberAngle(deg):" << divergentChamberAngle()  << "\n\n";
  std::cout << "chamberCrossArea(m^2):" << chamberCrossArea()   << "\n";
  std::cout << "chamberDiameter(m):" << chamberDiameter()  << "\n";
  std::cout << "chamberPressure(Pa):" << chamberPressure() << "\n";
  std::cout << "chamberTemperature(K)" << chamberTemperature()<< "\n\n";
  std::cout << "nozzleThroatCrossArea(m^2):" << nozzleThroatCrossArea()  << "\n";
  std::cout << "nozzleThroatDiameter(m):" << nozzleThroatDiameter()  << "\n";
  std::cout << "nozzleTemperature(K):" << nozzleTemperature()  << "\n";
  std::cout << "nozzlePressure(Pa):" << nozzlePressure() << "\n\n";

  

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

double chamberPressure() { 
  return 6894.75729*ChamberPressure;
} 

double chamberTemperature() {
  return 2.321*pow(10,-8)*pow(ChamberPressure,3) - 1.955*pow(10,-4)*pow(ChamberPressure,2) + 0.575*ChamberPressure + 3027.817;
}

double gamma() {
 return -6.988*pow(10,-13)*pow(ChamberPressure,3) + 6.032*pow(10,-9)*pow(ChamberPressure,2) - 1.823*pow(10,-5)*(ChamberPressure)+ 1.215; 
}

double mixtureRatio() {
  return 1.06*pow(10,-10)*pow((ChamberPressure),3) - 8.566*pow(10,-7)*pow(ChamberPressure, 2) + 2.224*pow(10,-3)*(ChamberPressure) + 4.151;
}
