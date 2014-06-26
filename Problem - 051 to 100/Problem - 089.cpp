/**
 * Run time solution
 * 0.00116377 seconds
 */
#include <cmath>
#include <iostream>
#include <map>
#include <string>

#include "numbers.hpp"


int main() {
    int solution = 0;
    
    const std::string mapping[4][10] = {
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "M", "MM", "MMM", "MMMM", "MMMMM"}
    };
    
    std::map<char, int> roman = { 
        {'M', 1000}, {'D', 500}, {'C', 100},
        {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}
    };
    
    for (const auto& e : numbers) {
        int number = 0;
        std::string optimized;
        
        for (unsigned i = 0; i < e.size() - 1; ++i) {
            if (roman[e[i]] < roman[e[i + 1]]) {
                number -= roman[e[i]];
            }
            else {
                number += roman[e[i]];
            }
        }
        number += roman[e[e.size() - 1]];
        
        for (int i = 3; number > 0; i--) {
            const int div = static_cast<int>(std::pow(10, i));
            optimized += mapping[i][number / div];
            number %= div;
        }
        
        solution += e.size() - optimized.size();
    }
    
    std::cout << "Solution: " << solution << std::endl;    
}

