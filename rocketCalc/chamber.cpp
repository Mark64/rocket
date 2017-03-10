#include "chamber.h"
#include "parameters.h"
#include "thrust.h"
#include "propellentFlow.h"
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
  return (propellentWeightFlow()/ChamberPressure)*pow(((1545.32/propellentMolecularWeight())*nozzleTemperature()*1.8)/(gamma()*32.2),0.5);
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
  return 89*nozzleThroatCrossArea();
}

double chamberVolumeL() {
  return chamberVolume()*1000;
}

double chamberThickness() {
  return ((ChamberPressure*ChamberDiameter*37.37)/1600)*0.0254;
}

double chamberLength() {
  return chamberVolume()/(1.1*chamberCrossArea());
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

  double result = 0;
  if (ChamberPressure < 301) {
    result = 3445.372;
  }
  else {
    result = 3512.039;
  }

  return result;
}

double gamma() {
 return 1.2; 
}

double mixtureRatio() {
  return 2.5;
}
