/**
 * Run time solution
 * 0.0382165 seconds
 */
#include <algorithm>
#include <cmath>
#include <iterator>
#include <iostream>
#include <set>


double op(double number1, double number2, int operation) {
    if (operation == 0) {
        return number1 + number2;
    }
    else if (operation == 1) {
        return number1 - number2;
    }
    else if (operation == 2) {
        return number1 * number2;
    }
    return number1 / number2;
}


int getDigits(const int digit1, const int digit2, const int digit3, const int digit4) {
    std::set<int> numbers;
    double result[4];
    int digits[] = {digit1,digit2,digit3,digit4};
    
    do {
        for (int op1 = 0; op1 < 4; op1++){
            for (int op2 = 0; op2 < 4; op2++){
                for (int op3 = 0; op3 < 4; op3++){
                    result[0] = op(op(op(digits[0], digits[1], op1), digits[2], op2), digits[3], op3);
                    result[1] = op(op(digits[0], digits[1], op1), op(digits[2], digits[3], op2), op3);
                    result[2] = op(op(digits[0], op(digits[1], digits[2], op1), op2), digits[3], op3);
                    result[3] = op(digits[3], op(digits[0], op(digits[1], digits[2], op1), op2), op3);
                    
                    for (const auto& e : result) {
                        if (e > 0 && fabs(floor(e) - e) < 0.0001) {
                            numbers.insert(e);
                        }
                    }
                }
            }
        }
    } 
    while (std::next_permutation(digits, digits + 4));
    
    int i = 1;
    auto it = numbers.begin();
    for (; it != numbers.end() && *it == i; ++it, i++);
    return i - 1;
}


int main() {
    int solution = 0;
    int currentMax = 0;
    
    for (int i = 1; i < 10; i++){
        for (int j = i + 1; j < 10; j++){
            for (int k = j + 1; k < 10; k++){
                for (int l = k + 1; l < 10; l++){
                    const int current = getDigits(i, j, k, l);
                    
                    if (current > currentMax){
                        currentMax = current;
                        solution = 1000 * i + 100 * j + 10 * k + l;
                    }
                }
            }
        }
    }
    
    std::cout << "Solution: " << solution << std::endl;
}
