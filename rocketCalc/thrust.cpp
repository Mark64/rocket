#include <iostream>
#include <cmath>
#include "chamber.h"
#include "propellentFlow.h"
#include "exit.h"
#include "thrust.h"
#include "parameters.h"
using namespace std;

void thrustCall() {
  cout << "Thrust Force: " << thrustForce() << " N\n";
  cout << "Specific Impulse: " << specificImpulse() << " s\n";
  cout << "Impulse Density: " << impulseDensity() << " s*kg/L\n\n";
}

double thrustForce() {
  return Thrust;
}

double specificImpulse() {
  double result = 0;
  if (ChamberPressure < 301) 
    result = 261;
  if (ChamberPressure > 301) 
    result = 279;
  return result;
}

double impulseDensity() {
  return specificImpulse()*propellentDensity();
}


