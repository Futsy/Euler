#include <iostream>
#include <string>

#include "BigIntegerLibrary.hh"


bool Palindrome(BigInteger  num) {
    BigInteger reverseNumber = 0;
    BigInteger originalNumber = num;
    
    if (num % 10 == 0) {
        return false;
    }
 
    while (num >= 1) {
        reverseNumber = (reverseNumber * 10) + (num % 10);
        num = num / 10;
    }
 
    return (originalNumber == reverseNumber);
}

bool Lychrel(const int number) {
	BigInteger newNumber = number;
    
	for (int i = 0; i < 50; i++) {
		std::string reverse = bigIntegerToString(newNumber);
		newNumber += stringToBigInteger(std::string(reverse.rbegin(), reverse.rend()));
        
		if (Palindrome(newNumber)) {
			return false;
		}
    }
    return true;
}

int main() {
	int solution = 0;
 
	for (int i = 1; i < 10000; i++) {
		if (Lychrel(i)) {
			solution++;
		}
	}
	std::cout << "Solution: " << solution << std::endl;
}