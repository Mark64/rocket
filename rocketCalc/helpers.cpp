// implementation for helpers.h
//
#include "helpers.h"


double getValueFromStdIn(std::string valueName) {

	std::cout<<" Enter "<<valueName<<"\n";
	double value = 0;
	std::cin >> value;

	return value;
}

