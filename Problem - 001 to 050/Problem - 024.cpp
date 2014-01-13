#include <iostream>
#include <algorithm>

int main () {
	int input[] = {0,1,2,3,4,5,6,7,8,9};

	std::sort(input,input+10);

	int count = 0;
  
	do {
		count++;
		if (count == 1000000) {
			std::cout << "Solution: ";
			for (int i = 0; i < 10; i++) {
				std::cout << input[i];
			}
		}
	} 
	while ( std::next_permutation(input,input+10) );
}