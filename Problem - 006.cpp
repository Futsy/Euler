#include <iostream>
#include <cmath>

int main() {
    int solution;
    int square = 1;
    int sum = 1;
        
    for (int i = 2; i <= 100; i++) {
        sum += std::pow(i,2);
        square += i;
    }
    
    solution = std::pow(square,2) - sum;

    std::cout << "Solution: " << solution;
}