#include <iostream>
#include <cmath>
#include <string>

int main() {
    int solution = 1;
    
    std::string total = "";
    
    auto nterms = { 1, 10, 100, 1000, 10000, 100000, 1000000 };
    
    for (int i = 1; i < 1000000; i++) {
        std::string addThis = std::to_string(i);
        
        total += addThis;
    }
    
    for (const auto& e : nterms) {
        solution *= total[e - 1] - '0';
    }
    
    std::cout << "Solution: " << solution << std::endl;
}