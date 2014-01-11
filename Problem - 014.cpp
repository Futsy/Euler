#include <iostream>

int main() {
    const int max = 1000000;
    
    unsigned long long solution = 0;
    unsigned long long solutionChain = 0;
    int currentNumber = 2;
    
    while (currentNumber != max) {
        unsigned long long chain = 0;
        unsigned long long currentCopy = currentNumber;
        
        while (currentCopy != 1) {
            chain++;

            if (currentCopy % 2 == 0) {
                currentCopy /= 2;
            }
            else {
                currentCopy = (currentCopy * 3) + 1;
            }
        }
        if (chain > solutionChain) {
            solutionChain = chain;
            solution = currentNumber;
        }
        ++currentNumber;
    }

    std::cout << "Solution: " << solution;
}