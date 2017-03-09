#include <iostream>
#include <cmath>
#include "chamber.h"
#include "propellentFlow.h"
#include "exit.h"
#include "thrust.h"
using namespace std;

void thrustCall() {
  cout << "Thrust Force (N):" << thrustForce() << "\n";
  cout << "Specific Impulse (s):" << specificImpulse() << "\n";
  cout << "Impulse Density (s*kg/L):" << impulseDensity() << "\n\n";
}

double thrustForce() {
  return specificImpulse()*propellentWeightFlow();
}

double specificImpulse() {
  return exitGasVelocity()/9.8125;
}

double impulseDensity() {
  return specificImpulse()*propellentDensity();
}


