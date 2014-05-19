#include <cmath>
#include <iostream>


int main() {
    int solution = 0;
    const int limit = 2000000;
    
    int low = 10000;
    for (int i = 1; i < 200; i++) {
        for (int j = 1; j < 200 - i; j++) {
            // ((x^2 + x ) * (y^2 + y)) / 4
            const int sol = ((((i * i) + i) * ((j * j) + j)) / 4);
            
            if (sol < limit / 2) {
                //speed up iterations
                continue;    
            }
            
            if (sol > (limit - low)) {
                const int possible = std::abs(sol - limit);
                if (possible < low) {
                    low = possible;
                    solution = i * j;
                }
                else {
                    break;    
                }
            }
        }
    }
    std::cout << "Solution: " << solution << std::endl;
}