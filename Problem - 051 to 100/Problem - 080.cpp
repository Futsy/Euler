#include "LargeInt.h"


/** Squares untill 100
 * 4, 9, 16, 25, 36, 49, 64, 81, 100 
 * 
 */
 
int Solve(const int n) {
    //! N is a square
    LargeInt upper("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    
    LargeInt t1 = 5 * n;
    LargeInt t2 = 5;
 
    while (t2 < upper) {
        if (t1 < t2) {
            t2 = (t2 / 10) * 100 + 5;            
            t1 *= 100;
        } 
        else {
            t1 -= t2;
            t2 += 10;
        }
    }
 
    int sum = 0;
    for(const auto e : LargeInt(t2 / 100).toString()){
        sum += (e - '0');
    }
    return sum;
}

int main() {
    int solution = 0;
	std::vector<int> squares = { 1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
 
    for (int i = 2; i <= 100; i++) {
        if (std::find(std::begin(squares), std::end(squares), i) != std::end(squares)) {
            continue;
        }
        solution += Solve(i);
    }
    std::cout << "Solution: " << solution << std::endl;
}