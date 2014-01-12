#include <iostream>
#include <vector>
#include <string>

const std::vector<std::string> lowList = {
    "one","two","three","four","five","six","seven","eight","nine","ten",
    "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
    "eighteen","nineteen"
};

const std::vector<std::string> medList = {
    "twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"
};

int main() { 
    int firstWords = 0;
    
    //Add the first list (0 to 19)
    for (const auto& e : lowList) {
        firstWords += e.size();    
    }
    
    int secondWords = 0;
    
    //Add 20 to 99
    int firstninesum = 0;
    for (int i = 0; i < 9; i++) {
        firstninesum += lowList[i].size();     
    }
    
    secondWords += firstninesum * 8;
    for (const auto& e : medList) {
        secondWords += e.size() * 10;    
    }
    
    //Add 100 to 999
    const int hundred = 7 * 9;
    const int hundredand = 9 * 990;
    const int multiSum = (secondWords + firstWords) * 9;
    const int prefixdigit = firstninesum * 100;
    
    int solution = multiSum + hundred + hundredand + prefixdigit 
    + (secondWords + firstWords) + 11;

    std::cout << "Solution: " << solution << std::endl;
}