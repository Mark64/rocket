#include "chamber.h"
#include <iostream>
#include <stdlib.h>
#include "propellentFlow.h"
#include "chamber.h"
#include "exit.h"
#include "thrust.h"
using namespace std;
double ChamberDiameter, ChamberPressure;

int main(int argc, char *argv[]) {

  ChamberDiameter = strtod(argv[1],NULL);
  ChamberPressure = strtod(argv[2],NULL);

  cout << "\n";

  chamberCall();
  
  cout << "\n";

  propellentFlowCall();

  cout << "\n";

  exitCall();

  cout << "\n";

  thrustCall();
}
