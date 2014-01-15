#include <iostream>
#include <string>
#include <algorithm>

bool Palindrome(unsigned long long int  num) {
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

std::string ToBinary(int number) {
    std::string result = "";

    do {
        if ((number & 1) == 0) {
            result += "0";
        }
        else {
            result += "1";
        }

        number >>= 1;
    } while( number );

    std::reverse(result.begin(), result.end());
    return result;
} 

int main() {
    int solution = 0;
    
    for (int i = 0; i < 1000000; i++) {
        if (Palindrome(i) && Palindrome(std::stoull(ToBinary(i)))) {
            solution += i;    
        }
    }
    
    std::cout << "Solution: " << solution << std::endl;
}