#include <iostream>
#include <algorithm>
#include "input.h"

std::vector<std::string> input = GetInput();

int main() {
	int solution = 0;
    
	std::sort(input.begin(), input.end());
	for (int i = 0; i < input.size(); i++) {
		int count = 0;
		for (const auto ch : input[i]) {
			count += static_cast<int>(ch) - 64;
		}
		solution += (i + 1) * count;
	}
    
	std::cout << "Solution: " << solution;
}
