#include <iostream>
 
int main(){
    int solution = 0;
    
    int length = 0; 
    int maxlength = 0;
    int newSum = 0;
 
    for(int i = 1; i < 997; i += 2){
        int summed = 1;
        
        for(int j = 0; j < i; j++) {
            summed = (summed * 10) % i;
        }
        
        newSum = summed;
        length = 0;
        do {
            length++;
            summed = (summed * 10) % i;
        } 
        while(summed != newSum);
        
        if(length > maxlength){
            maxlength = length;
            solution = i;
        }
    }
    std::cout << "Solution: " << solution << std::endl;
}