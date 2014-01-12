#include <iostream>
#include <vector>

bool IsAbun(const int number) {
	int divSum = 1;

	for(int i = 2; i <= number / 2;i++) {
		if(number % i == 0) {
			divSum += i;
		}
	}

	return (divSum > number);
}

int main() {
	int solution = 0;

	const int limit = 28123;

	std::vector<int> abundantNumbers;
	bool entries[limit];

	for (int i = 12; i < limit; i++) {
		if (IsAbun(i)) {
			abundantNumbers.push_back(i);
		}
	}
	
	int first = 0;
	int second = 0;
	for (unsigned int j = 0; j < abundantNumbers.size(); j++) {
		first = abundantNumbers[j];
		
		for (unsigned int k = 0; k < abundantNumbers.size(); k++) {
			second = abundantNumbers[k];
			
			if (first + second <= limit) {
				entries[first + second] = true;
			}
		}
	}
    
	for (int i = 0; i < limit; i++) {
		if (entries[i] == false) {
			solution += (i);
		}
	}
    
	std::cout << "Solution: " << solution;
}