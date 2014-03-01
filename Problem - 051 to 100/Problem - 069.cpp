#include <iostream>
#include <vector>

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
    int solution = 1;
    std::vector<int> primes;
    
    for (int i = 1; i < 150; i++) {
        if (Prime(i)) {
            primes.push_back(i);    
        }
    }
    
    
    for (int i = 0;; i++) {
        if (solution * primes[i] < 1000000) {
            solution *= primes[i];
        }
        else {
            break;    
        }
    }
    
    std::cout << "Solution: " << solution << std::endl;
}