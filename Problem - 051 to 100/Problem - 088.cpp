/**
 * Run time solution
 * 0.128102 seconds
 */
#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>


int main() {
    int solution = 0;
    
    constexpr int N = 12000;
    constexpr int L = 14001;
    
    //! Keep track of individual lists
    std::vector<std::unordered_set<int>> numbers(L);
    
    //! Array for Low N
    std::array<int, N + 1> k = {};

    for (int i = 2; i <= N; i++) {
        //Add negative i so: -2 + 1, -3 + 1
        numbers[i].insert(-i + 1);
     
        for (auto e : numbers[i]) {
            int current = i + i;
            
            for (int j = 2, newNumber = e - 1; j <= i && current < L; j++, newNumber--, current += i) {
                const int currentNew = current + newNumber;
                numbers[current].insert(newNumber);
                
                if (currentNew <= N && (current < k[currentNew] || k[currentNew] == 0)) {
                    k[currentNew] = current;
                }
            }
        }
    }
         
    std::unordered_set<int> s(std::begin(k), std::end(k));
    solution = std::accumulate(std::begin(s), std::end(s), 0);

    std::cout << "Solution: " << solution << std::endl;
}
