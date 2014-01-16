#include <iostream>
#include <cmath>
#include <string>

//Algorithm to check for pandigital found on SO
bool Pandigital(int n) {
    int digits = 0;
    int count = 0;
    int temp = 0;

    while (n > 0) {
        temp = digits;
        
        digits = digits | 1 << static_cast<int>((n % 10) - 1);
        if (temp == digits) {
            return false;
        }

        count++;
        n /= 10;
    }

    return digits == (1 << count) - 1;
}

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

int main() {
    int solution = 0;
    
    for (int i = 10; i < 10000000; i++) {
        if (Pandigital(i) && Prime(i)) {
            solution = i;    
        }
    }
    
    std::cout << "Solution: " << solution << std::endl;
}