#include "propellentFlow.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "parameters.h"
#include "chamber.h"
using namespace std;



void propellentFlowCall(){

  //meters
  //ChamberDiameter = strtod(argv[1],NULL);
  //psi
  //ChamberPressure = strtod(argv[2],NULL);


  cout << "Fuel Mass Flow (kg per s):" << fuelMassFlow() << "\n";

  cout << "Fuel Weight Flow (lb per s):" << fuelWeightFlow() << "\n";

  cout << "Fuel Volume Flow (liter per s):" << fuelVolumeFlow() << "\n\n";

  cout << "Oxidizer Mass Flow (kg per s):" << oxidizerMassFlow() << "\n";

  cout << "Oxidizier Weight Flow (lb per s):" << oxidizerWeightFlow() << "\n";

  cout << "Oxidizer Volume Flow (liter per s):" << oxidizerVolumeFlow() << "\n\n";

  cout << "Propellent Mass Flow (kg per s):" << propellentMassFlow() << "\n";

  cout << "Propellent Weight Flow (lb per s):" << propellentWeightFlow() << "\n";

  cout << "Propellent Volume Flow (liter per s):" << propellentVolumeFlow() << "\n";

  cout << "Propellent Density (kg per liter):" << propellentDensity() << "\n";

  cout << "Propellent Molecular Weight (g per mole):" << propellentMolecularWeight() << "\n";


  
}

double fuelMassFlow() {
  return fuelWeightFlow()*0.453592;
}

double fuelWeightFlow() {
  return propellentWeightFlow()/(mixtureRatio()+1);
}

double fuelVolumeFlow() {
  return fuelMassFlow()/0.0071;
}

double oxidizerMassFlow() {
  return oxidizerWeightFlow()*0.453592;
}

double oxidizerWeightFlow() {
  return propellentWeightFlow()*mixtureRatio()/(mixtureRatio()+1); 
}

double oxidizerVolumeFlow() {
  return oxidizerMassFlow()/1.141;
}

double propellentMassFlow() {
  return propellentWeightFlow()*0.453592;
}

double propellentWeightFlow() {
  return (nozzleThroatCrossArea()*1550)*(nozzlePressure()*0.000145038)/pow((65*(nozzleTemperature()*1.8/(32.2*gamma()))),0.5);
}

double propellentVolumeFlow() {
  return propellentMassFlow()/propellentDensity();
}


double propellentDensity() {
  return 0.001 * ( nozzlePressure() * propellentMolecularWeight() ) / ( nozzleTemperature() * 8.3144621 );
}


double propellentMolecularWeight() {
  return -2.89*pow(10,-14)*pow(ChamberPressure,4) + 3.94*pow(10,-10)*pow(ChamberPressure,3) - 1.962*pow(10,-6)*pow(ChamberPressure,2) + 4.228*pow(10,-3)*ChamberPressure + 10.23;
}

