#include "chamber.h"
#include <iostream>
#include <stdlib.h>
#include "propellentFlow.h"
#include "chamber.h"

double ChamberDiameter, ChamberPressure;

int main(int argc, char *argv[]) {

  ChamberDiameter = strtod(argv[1],NULL);
  ChamberPressure = strtod(argv[2],NULL);

  chamberCall();
  
  std::cout << "\n";

  propellentFlowCall();
  
}
