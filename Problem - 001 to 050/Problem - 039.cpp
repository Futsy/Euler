#include <iostream>

int Triangles(const int i) {
    int options = 0;
    
    for (long j = 2; j < (i / 3); j++) {
        const int a = i;
        const int b = i * j;
        const int c = 2 * (i - j);
        
        if(a * b % c == 0){
            options++;
        }
    }
    return options;
}

int main() {
    int solution = 0;
    int posibility = 0;
 
    for (int i = 10; i <= 1000; i += 2) {
        const int options = Triangles(i);
        
        if(options > posibility){
            posibility = options;
            solution = i;
        }
    }
    
    std::cout << "Solution: " << solution << std::endl;
}