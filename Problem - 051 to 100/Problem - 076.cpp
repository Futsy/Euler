#include <iostream>

constexpr int Partition(const int n, int current) {
    return (current == 0) ? 0 : 
        (n == 0) ? 1 : 
        (n < 0) ? 0 : 
        Partition(n, current - 1) + Partition(n - current, current);
}

int main() {
    //! Substract 1 for self (no 2 integers) 
    constexpr int solution = Partition(100, 100) - 1; 
    std::cout << "Solution: " << solution << std::endl;
}