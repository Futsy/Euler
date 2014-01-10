#include <iostream>
#include <vector>
#include <string>
#include <sstream>

const std::vector<std::string> lowList = {
    "one","two","three","four","five","six","seven","eight","nine","ten",
    "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
    "eighteen","nineteen"
};

const std::vector<std::string> medList = {
    "twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety","hundred"
};

int main() { 
    const int upperBound = 1000;
    
    int current = 1;
    int solution = 11;

    std::ostringstream os;

    while (current != upperBound) {
        if (current % 100 == 0) {
            solution += lowList[current / 100 - 1].size() 
            solution += medList[8].size();
        }
        else if (current % 10 == 0 && current > 19 && current < 100) {
            solution += medList[current / 10 - 2].size();
        }
        else {
            os.seekp(0);
            os << current;
            std::string digits = os.str();
            int remain = 0;
            
            const int digitSize = digits.size();
            
            switch (digitSize) {
            case 3:
                solution += lowList[(digits[0] - '0') - 1].size() 
                solution += medList[8].size() + 3;
                remain = std::stoi(digits.substr(1,2));
                break;
            case 2:
                if (digits[0] == '0') {
                    remain = std::stoi(digits.substr(1,1));
                }
                else {
                    remain = std::stoi(digits.substr(0,2));    
                }
                break;
            default:
                remain = current;
                break;
            }
            
            if (remain < 20) {
                solution += lowList[remain - 1].size();
            }
            else if (digits[digits.size() - 1] - '0' != 0) {
                solution += medList[remain / 10 - 2].size(); 
                solution += lowList[(digits[digits.size() - 1] - '0') - 1].size();
            }
        }
        ++current;
    }
    
    std::cout << "Solution: " << solution << std::endl;
}