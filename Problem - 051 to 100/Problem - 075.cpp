#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

unsigned GCD(unsigned u, unsigned v) {
    while (v != 0) {
        unsigned r = u % v;
        u = v;
        v = r;
    }
    return u;
}

int main() {
    /**
     * Wikipedia
     * 
     * Euclid's formula[1] is a fundamental formula for generating Pythagorean triples 
     * given an arbitrary pair of positive integers m and n with m > n. The formula 
     * states that the integers:
     * 
     *  a = m² - n²
     *  b = 2mn
     *  c = m² + n²
     * 
     * Despite generating all primitive triples, Euclid's formula does not produce all 
     * triples. This can be remedied by inserting an additional parameter k to the 
     * formula. The following will generate all Pythagorean triples uniquely:
     * 
     *  a = k * (m² - n²)
     *  b = k * (2mn)
     *  c = k * (m² + n²)
     * 
     * where m, n, and k are positive integers with m > n, m − n odd, and with m and 
     * n coprime.
     * 
     * Approach
     * 
     * Work from m² + n² as it is a integer sided right angle triangle.
     * limit ≤ 1.500.000
     * generateLimit < √(limit / 2)
     * 2 ≤ m < generateLimit   -> (1, 1, √2) is not a Pythagorean triple because √2 is not an integer
     * 1 ≤ n < m
     */
    int solution = 0;
    
    const int limit = 1500000;
    const int generateLimit = std::sqrt(limit / 2);
    
    std::vector<int> triangles;
    triangles.resize(limit);
    
    //! 2 ≤ m < generateLimit
    for (int m = 2; m < generateLimit; m++) {
        
        //! 1 ≤ n < m
        for (int n = 1; n < m; n++) {
            
            //!  m − n odd
            //! and with m and n coprime (GCD(n,m) == 1)
            if (GCD(n, m) == 1 && (m - n) % 2 == 1) {
                const int powM = m * m;
                const int powN = n * n;
                
                const int a = powM - powN;
                const int b = 2 * m * n;
                const int c = powM + powN;
                
                unsigned long long sum = a + b + c;
                for (;sum <= limit; sum += a + b + c){
                    triangles[sum]++;
                }
            }
        }
    }
    //! in exactly one way
    solution = std::count(std::begin(triangles), std::end(triangles), 1);
    
    std::cout << "Solution: " << solution << std::endl;
}