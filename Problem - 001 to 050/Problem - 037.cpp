#include <iostream>
#include <cmath>
#include <string>

bool IsPrime(int number){
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
    int eleven = 0;
    int i = 10;
    
    while (eleven != 11) {
        i++;
        if (i % 10 == 0) {
            continue;
        }
        
        std::string primeString = std::to_string(i);
        bool truncatable = true;
        
        for (unsigned int j = 1; j < primeString.size(); j++) {
            int currentLeft = std::stoi(primeString.substr(j,primeString.size()));
            int currentRight = std::stoi(primeString.substr(0,j));
            
            if (!IsPrime(currentLeft) || !IsPrime(currentRight)) {
                truncatable = false;    
            }
        }
        
        if (truncatable && IsPrime(i)) {
            eleven++;
            solution += i;
        }
    }
    
    std::cout << "Solution: " << solution << std::endl;
}