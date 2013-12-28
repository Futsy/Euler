#include <iostream>

int main() {
    int solution = 0;
    
    for(int i = 1; i <= 1000; i++) {
        if(i % 3 == 0 || (i % 5 == 0)) {
            solution = solution + i;
        }
    }
    
    std::cout << "Solution: " << solution;
    return 0;
}