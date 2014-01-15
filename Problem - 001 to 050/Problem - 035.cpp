#include <iostream>
#include <string>
#include <algorithm>

bool IsPrime(int number){
    if(number % 2 == 0) {
        return false;
    }
    for(int i = 3; (i * i) <= number; i += 2){
        if(number % i == 0 ) { 
            return false;
        }
    }
    return true;
}

int main() {
    int solution = 13;
    
    for (int i = 100; i < 1000000; i++) {
        if (!IsPrime(i)) {
            continue;
        }
        std::string evenCheck = std::to_string(i);
        bool leave = true;
        
        for (const auto& e : evenCheck) {
            if ((e - 48) % 2 == 0 || (e - 48) == 5) {
                leave = false;    
            }
        }
        
        while (leave) {
            std::rotate(evenCheck.begin(),evenCheck.begin() + 1, evenCheck.end());
            std::string reconstruct = "";
            
            const int newNumber = std::stoi(evenCheck);
            
            if (!IsPrime(newNumber)) {
                leave = false;
                break;
            }
            else if (i == newNumber) {
                break;    
            }
        }
        
        if (leave) {
            solution++;
        }
    }
    
    std::cout << "Solution: " << solution << std::endl;
}