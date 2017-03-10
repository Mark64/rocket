#include "chamber.h"
#include <iostream>
#include <stdlib.h>
#include "propellentFlow.h"
#include "chamber.h"
#include "exit.h"
#include "thrust.h"
#include "coolant.h"
#include "injector.h"
using namespace std;
double ChamberPressure, Thrust, ChamberDiameter;

int main(int argc, char *argv[]) {

  Thrust = strtod(argv[1],NULL);
  ChamberPressure = strtod(argv[2],NULL);
  ChamberDiameter = strtod(argv[3],NULL);

  cout << "\n";

  chamberCall();
  
  cout << "\n";

  propellentFlowCall();

  cout << "\n";

  exitCall();

  cout << "\n";

  thrustCall();
  
  cout << "\n";

  coolantCall();

  cout << "\n";

  injectorCall();
}
