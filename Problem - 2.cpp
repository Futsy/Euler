#include <iostream>

int main() {
    int solution = 0;
    
    const int limit = 4000000;
    
    int skip = 0;
    int first = 1;
    int second = 1;
    
    while ((second + first) < limit) {
        int newSecond = second + first;
        first = second;
        second = newSecond;
        
        if (skip > 0) {
            --skip;
            continue;
        }
        else {
            solution += second; 
            skip = 2;
        }
    }
    
    std::cout << "Solution: " << solution;
    return 0;
}