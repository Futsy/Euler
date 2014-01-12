#include <iostream>

const int arraySize = 104744;

int primes[arraySize];

void Sieve() {
    for (int i = 2; i < arraySize; i++) {
        int primeCount = 2;
        int primePos = i * primeCount;
        while (primePos < arraySize) {
            primes[primePos] = -1;
            primeCount++;
            primePos = i * primeCount;
        }
        
        if (primes[i] == 0) {
            primes[i] = 1;
        }
    }
}

int main() {
    int solution;
    
    Sieve();

    int primeCount = 0;
    for(int i = 0; i < arraySize; i++) {
        if(primes[i] == 1) {
            primeCount++;
            if (primeCount == 10001) {
                solution = i;
                std::cout << "Solution: " << solution;
                return 0;
            }
        }
    }
}