#include <iostream>

bool Prime(int number){
    if (number % 2 == 0) {
        return false;
    }
    for (int i = 3; (i * i) <= number; i += 2){
        if (number % i == 0 ) { 
            return false;
        }
    }
    return true;
}

int main() {
    int solution = 2;
    
    double count = 3.0;
    int temp1 = 9;
     
    while(count / (2 * solution + 1) > 0.1){
        solution += 2;
        for(int i = 0; i < 3; i++){
            temp1 += solution;
            
            if(Prime(temp1)) {
                count++;
            }
        }
        temp1 += solution;
    }
    solution++;
    
    std::cout << "Solution: " << solution << std::endl;
}