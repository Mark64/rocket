#include <iostream>
#include <cmath>
#include "chamber.h"
#include "propellentFlow.h"
#include "injector.h"
using namespace std; 

void injectorCall () {
  cout << "Orifice Area: " << orificeArea() << " \n";
  cout << "Pressure Drop: " << pressureDrop() << " \n";
  cout << "Discharge Coefficient: " << dischargeCoefficient() << " \n";
  cout << "Injection Velocity: " << injectionVelocity() << "\n\n";
}

double orificeArea() {
  return 0;
}

//pascals
double pressureDrop() {
  return 689475.729;
}

//arbitrary
double dischargeCoefficient() {
  return 1.7;
}

double injectionVelocity() {
  return dischargeCoefficient() * pow ( 2*32.2*pressureDrop()*0.02088547/propellentDensity(),0.5);
}
