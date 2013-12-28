#include <iostream>
#include <cstdlib>
 
int noRemainder(const int maxDiv) {
    int number = maxDiv;
    
    while (true) {
        bool foundIt = true;
        
        for (int i = 1; i <= maxDiv; i++) {
            std::div_t divResult = std::div(number,((maxDiv + 1) - i));     
            if (divResult.rem > 0) {
                foundIt = false;    
            }
        }
        
        if (foundIt) {
            return number;
        }
        else {
            number += maxDiv;
        }
    }
}

int main() {
    std::cout << "Solution: " << noRemainder(10);
}