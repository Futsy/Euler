/**
 * Run time solution
 * 0.000007742 seconds
 */
#include <iostream>

 
bool Palindrome(int num) {
    int reverseNumber = 0;
    int originalNumber = num;
    
    if (num % 2 == 0) {
        return false;
    }
 
    while (num >= 1) {
        reverseNumber = reverseNumber * 10 + (num % 10);
        num = num / 10;
    }
 
    return originalNumber == reverseNumber;
} 
 
int main() {        
    int solution = 0;
    
    for (int i = 999; i >= 900; --i) {
        int count = 0;
        int divider = 1; 
        
        if (i % 11 == 0) {
            count = 999;
        }
        else {
            count = 990;
            divider = 11;
        }
        
        while (count >= i) {
            if (i * count <= solution) {
                break;
            }
            
            if (Palindrome(i * count)) {
                solution = i * count;
            }
            
            count = count - divider;
        }
    }
    std::cout << "Solution: " << solution;
}

