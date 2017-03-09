#include <iostream>
#include <cmath>
#include "chamber.h"
#include "propellentFlow.h"
#include "exit.h"
#include "coolant.h"
using namespace std;

void coolantCall() {
  cout << "Heat Transferred: " << heatTransferred() << " \n";
  cout << "Heat Transfer Area: " << heatTransferArea() << " \n";
  cout << "Coolant Flow Rate: " << coolantFlowRate() << " \n";
  cout << "Specific Heat Coolant: " << specificHeatCoolant() << " \n";
  cout << "Temperature of Coolant Leaving: " << temperatureCoolantLeaving() << " \n";
  cout << "Temperature of Coolant Entering: " << temperatureCoolantEntering() << " \n\n";
}

double heatTransferred() {
  return 0.0;
}

double heatTransferArea() {
  return 0.0;
}

double coolantFlowRate() {
  return 0.0;
}

double specificHeatCoolant() {
  return 1.0;
}

double temperatureCoolantLeaving() {
  return 0.0;
}

double temperatureCoolantEntering() {
  return 0.0;
}
