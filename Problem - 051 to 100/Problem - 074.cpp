#include <iostream>
#include <set>
#include <algorithm>

const static int factorial[] = {
    1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880
};

int Factorial(int number) {
    int res = 0;
    while(number != 0) {
        res += factorial[number % 10];
        number /= 10;
    }
    return res;
}

int main() {
    int solution = 0;
    
    const int limit = 1000000;
    
    for(int i = 1; i < limit; i++) {
        auto currentIndex = i;
        std::set<int> facList;
        
        while(std::find(facList.begin(), facList.end(), currentIndex) == facList.end()) {
            facList.insert(currentIndex);
            currentIndex = Factorial(currentIndex);
        }
        if(facList.size() == 60) {
            solution++;
        }
    }
    
    std::cout << "Solution: " << solution << std::endl;
}