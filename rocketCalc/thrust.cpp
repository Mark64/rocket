#include <iostream>
#include <cmath>
#include "chamber.h"
#include "propellentFlow.h"
#include "exit.h"
#include "thrust.h"
using namespace std;

void thrustCall() {
  cout << "Thrust Force: " << thrustForce() << " N\n";
  cout << "Specific Impulse: " << specificImpulse() << " s\n";
  cout << "Impulse Density: " << impulseDensity() << " s*kg/L\n\n";
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


