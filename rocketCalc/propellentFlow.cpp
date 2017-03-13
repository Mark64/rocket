#include "propellentFlow.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "parameters.h"
#include "chamber.h"
#include "thrust.h"
using namespace std;



void propellentFlowCall(){

  //meters
  //ChamberDiameter = strtod(argv[1],NULL);
  //psi
  //ChamberPressure = strtod(argv[2],NULL);


  cout << "Fuel Mass Flow: " << fuelMassFlow() << " kg/s\n";

  cout << "Fuel Weight Flow: " << fuelWeightFlow() << " lb/s\n";

  cout << "Fuel Volume Flow: " << fuelVolumeFlow() << " L/s\n\n";

  cout << "Oxidizer Mass Flow: " << oxidizerMassFlow() << " kg/s\n";

  cout << "Oxidizier Weight Flow: " << oxidizerWeightFlow() << " lb/s\n";

  cout << "Oxidizer Volume Flow: " << oxidizerVolumeFlow() << " L/s\n\n";

  cout << "Propellent Mass Flow: " << propellentMassFlow() << " kg/s\n";

  cout << "Propellent Weight Flow: " << propellentWeightFlow() << " lb/s\n";

  cout << "Propellent Volume Flow: " << propellentVolumeFlow() << " L/s\n";

  cout << "Propellent Density: " << propellentDensity() << " kg/s\n";

  cout << "Propellent Molecular Weight: " << propellentMolecularWeight() << " g/mol\n";

  cout << "Propellent Gas Constant: " << propellentGasConstant() << "\n";
  
}

double fuelMassFlow() {
  return fuelWeightFlow()*0.453592;
}

double fuelWeightFlow() {
  return propellentWeightFlow()/(mixtureRatio()+1);
}

double fuelVolumeFlow() {
  return fuelMassFlow()/0.71;
}

double oxidizerMassFlow() {
  return oxidizerWeightFlow()*0.453592;
}

double oxidizerWeightFlow() {
  return propellentWeightFlow()*mixtureRatio()/(mixtureRatio()+1); 
}

double oxidizerVolumeFlow() {
  return oxidizerMassFlow()/0.001429;
}

double propellentMassFlow() {
  return propellentWeightFlow()*0.453592;
}

double propellentWeightFlow() {
  return Thrust/specificImpulse();
}

double propellentVolumeFlow() {
  return propellentMassFlow()/propellentDensity();
}


double propellentDensity() {
  return 0.001 * ( nozzlePressure() * propellentMolecularWeight() ) / ( nozzleTemperature() * 8.3144621 );
}

//assuming fuel-rich
//Molecular weight g/mol 
double propellentMolecularWeight() {
  return 22.714;
}

double propellentGasConstant() {
  return 366.029;
}


