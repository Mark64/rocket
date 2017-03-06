#include <iostream>
#include "cdiameter.h"
#include <cmath>
#include <stdlib.h>

int main( int argc , char  *argv[] ) {

  setChamberDiameter(strtod(argv[1],NULL));
  std:: cout << "Chamber Area: " << getChamberArea() << "\n";
  std:: cout << "Nozzle Area: " << getNozzleArea() << "\n";
  std:: cout << "Nozzle Diameter: " << getNozzleDiameter() << "\n";
  std:: cout << "Chamber Diameter: " << getChamberDiameter() << "\n";

  return 0;

}


double getChamberArea() {
  return pow(ChamberDiameter/2,2)*3.1459;
}

double getNozzleArea() { 
  return getChamberArea()/3;
}

double getNozzleDiameter() {
  return pow(4*getNozzleArea()/3.14159,0.5);

}

double getChamberDiameter() {
  return ChamberDiameter;
}


void setChamberDiameter(double cd) { 
  ChamberDiameter = cd;
}


