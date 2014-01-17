#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#include <chrono>
#include <ctime>

bool Prime(int number){
    if (number == 1) {
        return false;    
    }
    if (number == 2) {
        return true;    
    }
    if (number % 2 == 0) {
        return false;
    }
    for (int i = 3; (i * i) <= number; i += 2){
        if (number % i == 0 ) { 
            return false;
        }
    }
    return true;
}

int main() { 
    int solution = 0;
    const int max = 300000;

    std::vector<int> composites;
    std::vector<int> primes;
	primes.push_back(2);
    primes.push_back(3);
	primes.push_back(5);
	primes.push_back(7);
	std::vector<int> squares;
    std::vector<int> result;

    //Obtain composites and primes under max
    for (int i = 10; i < max; i++) {
        if (!Prime(i)) {
            composites.push_back(i);
        }
        else {
            primes.push_back(i);    
        }
        squares.push_back(2 * (std::pow(i - 9,2))); 
    }
    
    //Brute force compare
    for (int i = 0; i < max; i++) {
        const int current = composites[i];
		if (current % 2 == 0) {
			continue;
		}

        bool foundIt = false;
        
        for (const auto& e : primes) {
            for (const auto& f : squares) {
                if (f + e == current) {
                    foundIt = true;
                    break;
                }
            }
            if (foundIt) {
                break;    
            }
        }
        if (!foundIt && current % 2 != 0) {
            solution = current;
			break;
        }
    }
    std::cout << std::endl << "Solution: " << solution << std::endl;
}