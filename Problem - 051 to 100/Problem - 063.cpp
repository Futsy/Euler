#include <iostream>
#include <cmath>

int main() {
    int solution = 0;
    
    for (int n = 1;; n++) {
        const int difference = std::ceil(std::pow(10,(n - 1.0) / n)); 
        solution = solution +  10 - difference;
        
        if (10 - difference <= 0) {
            break;
        }
    }
    
    std::cout << "Solution: " << solution << std::endl;
}