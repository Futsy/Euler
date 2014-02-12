#include <iostream>
#include <cmath>

int main() {
    //http://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Continued_fraction_expansion
    int solution = 0;
    
    const int max = 10000;
    for (int n = 2; n <= max; n++) {        
        int sqrtN = static_cast<int>(std::sqrt(n));
        
        if (std::pow(sqrtN,2) == n) {
            continue;    
        }
        
        int p = 0;
        int m = 0; //m0 = 0
        int d = 1; //d0 = 1
        int a = sqrtN; //a0 = sqrt S
        
        do {
            p++;
            m = d * a - m;
            d = (n - m * m) / d;
            a = (sqrtN + m) / d;
        }
        while (a != 2 * sqrtN);
        
        if (p % 2 == 1) {
            solution++; //uneven ending  
        }
    }
    std::cout << "Solution: " << solution << std::endl;
}