#include <iostream>
#include <cmath>

int main() {
    int solution = 0;
    
    const int sum = 1000;
    int a = 0;
    int b = 0;
    int c = 0;
    
    for (a = 1; a < sum / 3; a++) {
        b = a;
        for (; b < sum / 2; b++) {
            c = sum - b - a;
     
            if (std::pow(a,2) + std::pow(b,2) == std::pow(c,2)) {
                solution = a * b * c;
                std::cout << "Solution: " << solution;
                return 0;
            }
        }
    }
}