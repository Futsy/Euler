#include <iostream>
#include <string>

#include "BigIntegerLibrary.hh"

int main() {
	int solution = 0;
	BigInteger power = stringToBigInteger("2");
	
	for (int i = 1; i < 1000; i++) {
		power *= 2;
	}

	std::string chars = bigIntegerToString(power);

	for (auto& e : chars) {
		solution += (e - 48);
	}

    std::cout << "Solution: " << solution;
	std::cin.get();
}