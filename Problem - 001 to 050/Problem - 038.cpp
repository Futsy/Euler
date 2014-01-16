#include <iostream>

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


int main() {
    int solution = 0;
    
    for (long i = 9387; i >= 9234; i--) {
        int copyItwo = 2 * i;
        int loop = copyItwo;
        int copyI = i;
        
        while (loop > 0) {
            copyI *= 10;
            loop /= 10;
        }
        
        solution = copyI + copyItwo;
        
        if(Pandigital(solution)){
            break;
        }
    }
    
    std::cout << "Solution: " << solution << std::endl;
}