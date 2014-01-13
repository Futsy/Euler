#include <iostream>
#include <cmath>

bool Prime(const int number) {
    if (number == 2) {
        return true;    
    }
    if(number <= 0 || number == 1 || number % 2 == 0) {
        return false;    
    }

    for(int i = std::sqrt(number) + 1; i >= 2; i--) {
        if(number % i == 0) {
            return false;
        }
    }
    return true;
}

int main () {
    int solution = 0;
    int maxChain = 0;
 
    for (int i = -1000; i <= 1000; i++) {
        for(int j = -1000; j <= 1000; j++){
            int chain = 0;
            
            while(Prime(std::pow(chain,2) + (i * chain) + j)) {
                chain++;
            }
     
            if (chain > maxChain) {
                maxChain = chain;
                solution = i * j;
            }
        }
    }
    std::cout << "Solution: " << solution << std::endl;
}