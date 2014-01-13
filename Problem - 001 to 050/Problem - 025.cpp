#include <iostream>

#include "BigIntegerLibrary.hh"
 
int main() {
	int solution = 0;
	int count = 0;
   
	BigInteger first = 0;
	BigInteger second = 1
	BigInteger next = 0;
 
	const int limit = 5000;
 	for(int i = 0 ; i < n ;i++) {
		if (i <= 1) {
			next = i;
		}
		else {
			next = first + second;
			first = second;
			second = next;
		}
		if (std::to_string(next).size() == 1000) {
			solution = count;
			break;
        	}
		count++;
	}
   	std::cout << "Solution: " << solution << std::endl;
}