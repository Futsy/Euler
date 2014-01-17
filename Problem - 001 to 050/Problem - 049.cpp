#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <array>

bool Prime(int number){
    if (number == 1) {
        return false;    
    }
    if (number == 2) {
        return true;    
    }
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
    std::string solution = "";
    
    for (int i = 1000; i < 10000; i++) {
        if (!Prime(i) || !Prime(i + 3330) || !Prime(i + 6660)) {
            continue;    
        }
        
        std::string first = std::to_string(i);
        std::string second = std::to_string(i + 3330);
        std::string third = std::to_string(i + 6660);
        
        
        const std::array<int,4> perm1 = { first[0] - '0', first[1] - '0', first[2] - '0', first[3] - '0' };
        const std::array<int,4> perm2 = { second[0] - '0', second[1] - '0', second[2] - '0', second[3] - '0' };
        const std::array<int,4> perm3 = { third[0] - '0', third[1] - '0', third[2] - '0', third[3] - '0' };
        
        if ( std::is_permutation(perm2.begin(), perm2.end(), perm1.begin())
            && std::is_permutation(perm3.begin(), perm3.end(), perm1.begin())
            && i != 1487) {
            solution = first + second + third;
            break;
        }
    }
    
    std::cout << "Solution: " << solution << std::endl;
}