#include <iostream>

bool Prime(int number){
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

int main () {
    int solution = 0;
    const int max = 1000000;

    int largestNum = 0;
    for (int i = 1; i < max / 10; i++) {
        int sum1 = 0;
        for (int j = i; j < max; j++) {
            if (!Prime(j)) {
                continue;    
            }
            sum1 = sum1 + j;
            
            if (sum1 >= max) {
                break;
            }
            if (Prime(sum1) && ( j - i > largestNum)) {
                solution = sum1; 
                largestNum = j - i;
            }
        }
    }

    std::cout << "Solution: " << solution << std::endl;
}