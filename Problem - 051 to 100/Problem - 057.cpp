#include <iostream>
#include <string>

#include "BigIntegerLibrary.hh"

int main() {
	int solution = 0;
    
	BigInteger t1 = 3;
	BigInteger t2 = 2;
 	BigInteger first = 7;
	BigInteger second = 5;
    
	for (int i = 1; i < 1001; i++) {
       	BigInteger temp1 = t1;
       	BigInteger temp2 = t2;
       	t1 = first;
       	t2 = second;
       	first = first + first + temp1;
       	second = second + second + temp2;
        
       	auto size1 = bigIntegerToString(first).size();
       	auto size2 = bigIntegerToString(second).size();
        
       	if (size1 > size2) {
            		solution++;    
        	}
    	}
    
    	std::cout << "Solution: " << solution << std::endl;
}