#include <iostream>
#include <string>

#include "BigIntegerLibrary.hh"

int main() {
	unsigned long long solution = 0;
 
	BigInteger current;
	//a
	for (int i = 0; i < 100; i++) {
		//^b
		for (int j = 0; j < 100; j++) {
			current = i;
			
			for (int k = 0; k < j; k++) {
				current = current * i;
			}
			std::string currentString = bigIntegerToString(current);
			unsigned long long sum = 0;
			for (const auto& e : currentString) {
				sum += e - '0';
			}

			if (sum > solution) {
				solution = sum;
			}
		}
	}

	std::cout << "Solution: " << solution << std::endl;
}