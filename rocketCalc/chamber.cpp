#include "chamber.h"
#include "parameters.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;


void chamberCall() {

  
  cout << "Gamma: " << gamma()  << "\n";
  cout << "Ratio: " << mixtureRatio() << "\n\n";
  
  cout << "Convergent Chamber Angle: " << convergentChamberAngle()  << " deg\n";
  cout << "Divergent Chamber Angle: " << divergentChamberAngle()  << " deg\n\n";
  
  cout << "Chamber Cross Area: " << chamberCrossArea()   << " m^2\n";
  cout << "Chamber Diameter: " << chamberDiameter()  << " m\n";
  cout << "Chamber Pressure: " << chamberPressure() << " Pa\n";
  cout << "Chamber Temperature: " << chamberTemperature()<< " K\n";
  cout << "Chamber Volume: " << chamberVolume() << " m^3\n";
  cout << "Chamber Volume: " << chamberVolumeL() << " L\n";
  cout << "Chamber Thickness: " << chamberThickness() << " m\n";
  cout << "Chamber Length: " << chamberLength() << " m\n";
  cout << "Contraction Ratio: " << contractionRatio() << "\n\n";

  cout << "Nozzle Throat Cross Area: " << nozzleThroatCrossArea()  << " m^2\n";
  cout << "Nozzle Throat Diameter: " << nozzleThroatDiameter()  << " m\n";
  cout << "Nozzle Temperature: " << nozzleTemperature()  << " K\n";
  cout << "Nozzle Pressure: " << nozzlePressure() << " Pa\n\n";


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

double chamberVolume() {
  return chamberLength()*nozzleThroatCrossArea();
}

double chamberVolumeL() {
  return chamberVolume()*1000;
}

double chamberThickness() {
  return ((ChamberPressure*ChamberDiameter*37.37)/1600)*0.0254;
}

double chamberLength() {
  return exp( 0.0029 * log( nozzleThroatDiameter() * 100.0 ) * log(nozzleThroatDiameter() * 100.0 ) + 0.47 * log (nozzleThroatDiameter() * 100.0 ) + 1.94 )/100;
  // return chamberVolume()/(1.1*chamberCrossArea());
}

double contractionRatio() {
  return chamberCrossArea()/nozzleThroatCrossArea();
}

double nozzleTemperature() {
  return chamberTemperature()*( 1 / ( 1 + ( gamma() - 1) / 2 ) );
}


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
