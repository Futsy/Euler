/**
 * Run time solution
 * 0.000067825 seconds
 */
#include <iostream>


int main() {
    int solution = 13;
    long long num = 600851475143;

    while (num > 1) {
        if (num % solution == 0) {
            num = num / solution;    
        }
        else {
            solution += 2;    
        }
    }
    
    std::cout << "Solution: " << solution;
}
