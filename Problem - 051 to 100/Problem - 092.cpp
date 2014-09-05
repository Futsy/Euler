/**
 * Run time solution
 * 4.20805 seconds
 */
#include <iostream>
#include <vector>


void collect_digits(std::vector<int>& digits, unsigned long num) {
    if (num > 9) {
        collect_digits(digits, num / 10);
    }
    const int digit = num % 10;
    digits.push_back(digit * digit);
}


int main() {
    int solution = 0;
    std::vector<bool> range(10000000, false);

    for (int i = 2; i < 10000000; i++) {
        std::vector<int> digits;
        std::vector<int> sequence;
        int current = std::move(i);
        
        while (current != 1) {
            sequence.push_back(current);
            
            if (range[current] || current == 89) {
                solution++;
                for (const auto& e : sequence) {
                    range[e] = true;    
                }
                
                break;
            }
            
            digits.clear();
            collect_digits(digits, current);
            current = 0;
            
            for (const auto& e : digits) {
                current += e;
            }
        }
    }

    std::cout << "Solution: " << solution;
}