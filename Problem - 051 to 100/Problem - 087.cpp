#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>


std::vector<int> SieveAtkin(const int upper = 10000) {
    bool sieve[upper];
    memset(sieve, 0, sizeof(sieve));
    
    std::vector<int> primes { 2, 3 };
    
    const int upperSqrt = std::sqrt(upper);
    for (int i = 1; i <= upperSqrt; i++) {
        for (int j = 1; j <= upperSqrt; j++) {
            const int baseNum = ( j * j);
            
            const int first = baseNum + (4 * i * i);
            if (first <= upper && (first % 12 == 1 || first % 12 == 5)) {
                sieve[first] ^= true;
            }
            
            const int second = baseNum + (3 * i * i);
            if (second <= upper && second % 12 == 7) {
                sieve[second] ^= true;
            }
            
            const int third = (3 * i * i) - baseNum;
            if (i > j && third <= upper && third % 12 == 11) {
                sieve[third] ^= true;
            }
        }
    }
    sieve[2] = true;
    sieve[3] = true;

    int i = 5;
    for (; i <= upperSqrt; i += 2) {
        if (sieve[i]){
            for (int j = i * i; j < upper; j += i * i) {
                sieve[j] = false;
            }
            primes.push_back(i);
        }
    }
    
    for (; i < upper; i += 2) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}


std::vector<std::vector<int>> PrimePowers(const int n, const int high) {
    auto primes = SieveAtkin(high);
    
    std::vector<std::vector<int>> power;
    power.resize(n);
    
    for (int i = 2; i < (n + 2); i++) {
        std::vector<int> copyList;
        copyList.resize(primes.size());
        
        for (int j = 0; j < primes.size(); j++) {
            copyList[j] = std::pow(primes[j], i);
        }
        power[i - 2] = copyList;
    }
    return power;
}


int main() {
    const int upper = 50000000;
    
    auto power = PrimePowers(3, 7071);
    std::set<int> solution;
    for (const auto& e : power[0]) {
        if (e > upper) {
            break;    
        }
        for (const auto& f : power[1]) {
            if (f > upper) {
                break;    
            }
            for (const auto& g : power[2]) {
                int number = e + g + f;
                if (number > upper) {
                    break;
                }
                solution.insert(number);
            }
        }
    }
    
    std::cout << solution.size() << std::endl;
}