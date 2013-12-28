#include <iostream>
 
bool Palindrome(int num) {
    int reverseNumber = 0;
    int originalNumber = num;
    
    if (num % 10 == 0) {
        return false;
    }
 
    while (num >= 1) {
        reverseNumber = (reverseNumber * 10) + (num % 10);
        num = num / 10;
    }
 
    return (originalNumber == reverseNumber);
}
 
int main() {
    int solution = 0;
    int sum;
    int first = 999;
    int second = 999;
    long int limit = 10000;
 
    while (limit > 0) {
        first = 999;
        limit--;
        
        while (first > 900) {
            second = 999;
            
            while (second >= first) {
                sum = first * second;
                second--;
                
                if (sum > solution && Palindrome(sum)) {
                    solution = sum;
                }       
            }
            first--;
        }
    }
    std::cout << "Solution: " << solution;
}