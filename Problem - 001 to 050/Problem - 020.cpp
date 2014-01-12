#include <iostream>
#include <string>

#include "BigIntegerLibrary.hh"

int main() {
	int solution = 0;

	BigInteger product = 1;
	int counter = 100;
 
	while (counter > 0) {
        	product = product * counter;
        	counter--;
	}
	
	std::string result = bigIntegerToString(product);
	for (const auto& e : result) {
		solution += (e - '0');
	}	
 
	std::cout << "Solution: " << solution;
}