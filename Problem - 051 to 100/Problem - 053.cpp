#include <iostream>

int main() {
    const int limit = 1000000;
    const int choices = 101;
    int solution = -20;
    int options[choices][choices];
    
    for (int i = 0; i <= choices - 1; i++) {
        options[i][0] = 1;
    }
     
    for (int i = 1; i <= choices - 1; i++) {
        for (int j = 1; j <= i; j++) {
            options[i][j] = options[i - 1][j] + options[i - 1][j - 1];
            if (options[i][j] > limit) {
                solution++;
                options[i][j] = limit;
            }
        }
    }
    
    std::cout << "Solution: " << solution << std::endl;
}