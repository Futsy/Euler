#include <iostream>

constexpr int EvenFibonacciSum(const int high, int old, int current) {
    return old + current > high ? current 
        : ((old % 2 == 0) ? old : 0) 
        + EvenFibonacciSum(high, current, old + current);
}

int main() {
    constexpr int solution = EvenFibonacciSum(4000000, 1, 2);
    std::cout << "Solution: " << solution << std::endl;
}
