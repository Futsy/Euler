#include <iostream>

int main() {
    //Go -1 for 1 offset loop
    int solution = -1;

    for (int i = 1; i < 400000; i++) {
        int sumPowerTotal = 0;
        int cnumber = i;
        
        while (cnumber > 0) {
            int modNum = cnumber % 10;
            cnumber /= 10;
    
            int sumPower = modNum;
            
            for(int j = 1; j < 5; j++){
                sumPower *= modNum;
            }
            
            sumPowerTotal += sumPower;
        }
    
        if (sumPowerTotal == i) {
            solution += i;
        }
    }
    std::cout << solution;
}