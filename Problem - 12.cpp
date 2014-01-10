#include <iostream>
#include <cmath>

int CountDiv(int number) {
    int count = 0;
    int root = static_cast<int>(std::sqrt(number));
 
    for(int i = 1; i <= root; i++){
        if(number % i == 0){
            count += 2;
        }
    }
    
    if (std::pow(root,2) == number) {
        count--;
    }
 
    return count;
}


int main() {
    const int neededDivs = 1000;
    int solution = 0;
    int triangleSum = 1;
     
    while(CountDiv(solution) < neededDivs){
        solution += triangleSum;
        triangleSum++;
    }
    
    std::cout << "Solution: " << solution; 
}