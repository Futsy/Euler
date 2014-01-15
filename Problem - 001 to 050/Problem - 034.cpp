#include <iostream>
#include <cmath>
#include <string>
#include <vector>

template <int n>
struct Factorial {
    enum { value = n * Factorial<n - 1>::value };
};

template <>
struct Factorial<0> {
    enum { value = 1 };
};

int main() {
    int solution = 0;
    
    std::vector<int> factorials = { 
        Factorial<0>::value, Factorial<1>::value, Factorial<2>::value, Factorial<3>::value,
        Factorial<4>::value, Factorial<5>::value, Factorial<6>::value, Factorial<7>::value,
        Factorial<8>::value, Factorial<9>::value
    };
    
    for (int i = 3; i < 3000000; i++) {
        std::string stringNumber = std::to_string(i);
        int tempSum = 0;
        
        for (const auto& e : stringNumber) {
            tempSum += factorials[e - 48];        
        }
        if (tempSum == i) {
            solution += i;    
        }
    }
    
    std::cout << "Solution: " << solution << std::endl;
}
    