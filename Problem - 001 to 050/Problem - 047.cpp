#include <iostream>
 
int DistinctFactors(int number) {
	int distinct = 0;
	for(int i = 2; number != 1; i++) {
		if(number % i == 0) {
			distinct++;
			while(number % i == 0) {
				number = number / i;
			}
		}
	}
	return distinct;
}
 
int main() {
	int solution = 0;
	
	for(int i = 2; i > 0; i++) {
		if(solution == 4) {
     		solution = i - 4;
 			break;
		}
		if(DistinctFactors(i) == 4) {
  			solution++;
		}
		else {
      		solution = 0;
		}
	}
	std::cout << "Solution: " << solution << std::endl;
}
