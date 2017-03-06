// Contains functions for calculating total thrust and efficiency for the thruster
//

#include<iostream>


// returns the thrust in units of newtons
double thrustForce(double exitVelocity, double propellentFlow);

// returns the efficiency of the thruster in units of seconds (this is specific impulse)
double specificImpulse(double thrust, double propellentFlow);  



