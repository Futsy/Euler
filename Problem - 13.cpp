#include <iostream>

//std::vector<BigInteger> input
#include "input.h"


int main() {
	BigInteger solution;

	for (const auto& e : input) {
		solution += e;
	}

	std::cout << "Solution: " << solution;
}