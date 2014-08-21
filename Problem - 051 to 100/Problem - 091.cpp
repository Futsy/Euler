/**
 * Run time solution
 * 0.000227776 seconds
 */
#include <iostream>
#include <cmath>


unsigned Gcd(unsigned u, unsigned v) {
    while (v != 0) {
        unsigned r = u % v;
        u = v;
        v = r;
    }
    return u;
}


int main() {
    int solution = 0;

    for (int i = 1; i <= 50; i++) {
    	for (int j = 1; j <= 50; j++) {
    		const int gcd = Gcd(i, j);
    		solution += std::min(j / (i / gcd), (50 - i) / (j / gcd));
    	}
    }

	std::cout << "Solution: " << (solution * 2 + 7500) << std::endl;
}
