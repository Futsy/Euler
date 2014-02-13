#include <iostream>
#include <cmath>
#include <string>

#include "BigIntegerLibrary.hh"

int Sum(BigInteger n) {
    std::string nStr = std::to_string(n);
    
    int ds = 0;
    feor (const auto e : nStr) {                
        ds += e - '0';
    }
    return ds;
}

int main() {
    const int max = 100;
    int solution = 0;
     
    BigInteger d = 1;
    BigInteger n = 2;
     
    for (int i = 2; i <= max; i++) {
        BigInteger b = d;
        int c = (i % 3 == 0) ? 2 * (i / 3) : 1;
        d = n;
        n = c * d + b;
    }
    solution = Sum(n); 
    
    std::cout << "Solution: " << solution << std::endl;
}