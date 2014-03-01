#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>

bool Prime(int number){
    if (number == 1) {
        return false;    
    }
    if (number == 2) {
        return true;    
    }
    if (number % 2 == 0) {
        return false;
    }
    for (int i = 3; (i * i) <= number; i += 2){
        if (number % i == 0 ) { 
            return false;
        }
    }
    return true;
}

bool Perm(std::string str1, std::string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    
    return str1 == str2;
}

int main() {
    int solution = 0;
    double currentMin = 10000000;
    const int limit = 10000000;
    const int primeSize = 10000;
    
    std::vector<int> primes;
    
    for (int i = 0; i < primeSize; i++) {
        if (Prime(i)) {
            primes.push_back(i);    
        }
    }
    
    for (unsigned i = 1; i < primes.size(); i++) {
        for (int j = i - 1; j - 1 > 0; j--) {
            int first = primes[i];
            int second = primes[j];
            
            //Check if n passes max
            const int n = first * second;
            if (n > limit) {
                continue;
            }
            
            const double nd = static_cast<double>(n);
            int phi = n - first - second + 1;
            if (nd / phi < currentMin) {
                if (!Perm(std::to_string(n), std::to_string(phi))) {
                    continue;    
                }
                
                currentMin = nd / phi;
                solution = n;
            }
        }
    }
    std::cout << "Solution: " << solution << std::endl;
}
