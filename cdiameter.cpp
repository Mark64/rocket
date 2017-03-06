#include "cdiameter.h"
#include <cmath>

int main(){

  return 0;
};


double Dimensions::getChamberArea() {
  return pow(ChamberDiameter/2,2)*3.1459;
}

double Dimensions::getNozzleArea() {
  return getChamberArea()/3;
}

double Dimensions::getNozzleDiameter(){
  return pow(4*getNozzleArea()/3.14159,0.5);
}

double Dimensions::getChamberDiameter(){
  return ChamberDiameter;
}

void Dimensions::setChamberDiameter(double cd) {
  ChamberDiameter = cd; 
}



