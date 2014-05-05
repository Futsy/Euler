#include <cmath>
#include <cstdint>
#include <iostream>

//static std::uint_fast32_t numbers[80][80];
 
int main(){
    int solution = 0;
    const int size = 80;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i >= 1 && j >= 1) {
                numbers[i][j] = numbers[i][j] + std::min(numbers[i - 1][j], numbers[i][j - 1]); 
            }
            else if (i < 1 && j >= 1) {
                numbers[i][j] = numbers[i][j] + numbers[i][j - 1];
            }
            else if (j < 1 && i >= 1) {
                numbers[i][j] = numbers[i][j] + numbers[i - 1][j];
            }
            else { 
                numbers[i][j] = numbers[i][j];
            }
        }
    }
    solution = numbers[size - 1][size - 1];
    std::cout << "Solution: " << solution << std::endl;
}