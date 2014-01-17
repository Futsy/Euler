#include <iostream>
#include <cmath>
#include <string>

#include "BigIntegerLibrary.hh"

int main() {
	BigInteger solution;
	
	for (int i = 1; i < 1000; i++) {
		BigInteger number = i;
		for (int j = 0; j < i - 1; j++) {
			number *= i;
		}
		solution += number;
	}

	std::cout << "Solution: " << 
		bigIntegerToString(solution).substr(
		bigIntegerToString(solution).size() - 10, 
		bigIntegerToString(solution).size()) 
		<< std::endl;
}
