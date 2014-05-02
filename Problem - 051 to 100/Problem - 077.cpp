#include <algorithm>
#include <iostream> 
#include <map>
#include <set>


class PrimePartition {
    using fint = std::uint_fast32_t;
    using fint64 = std::uint_fast64_t;
    
public:
    const fint Kappa(const unsigned n) {
        if (memo.count(n))
            return memo[n];
        else {
            auto val = _Kappa(n);
            memo[n] = val;
            return val;
        }
    }
    
    const fint _Kappa(const unsigned n) {
        if (n == 0) {
            return 1;    
        }
        
        //! 1 / n
        const float div = static_cast<long double>(1.0) / n;
        
        //! sopf(n)
        const fint sumN = SumOfDPrimeFactors(n);
        
        //! Σ(j = 1, n - 1)
        fint64 sum = 0;
        for (fint j = 1; j <= n - 1; j++) {
            const fint sumJ = SumOfDPrimeFactors(j);
            sum += (sumJ * Kappa(n - j));
        }
        
        return div * (sumN + sum);
    }

private:
    fint SumOfDPrimeFactors(const unsigned n) { 
         std::set<fint> distinct;
         
    	 for(fint i = 2; i <= n; i++) {
    		 if(n % i == 0
             && std::find(std::begin(primes), std::end(primes), i) != std::end(primes)) {
                distinct.insert(i);
    		 }
    	 }
         
        return std::accumulate(std::begin(distinct), std::end(distinct), 0);
    }

private:
    const int primes[26] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 
        47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101    
    };
    
    std::map<int, int> memo;
};

int main() {
    int solution = 0;
    
    PrimePartition p;
    for (int i = 0; i < 100; i++) {
        if (p.Kappa(i) > 5000) {
            solution = i;
            break;
        }
    }
    std::cout << "Solution: " << solution;
}
