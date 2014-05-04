#include <chrono>
#include <cstdint>
#include <iostream>
#include <vector>


int main() {
    int solution = 0;
    
    std::vector<int> partitions = { 1 };
    partitions.resize(60000);
        
    for (int i = 1, p = 1;; i++) {
        p = 1;
     
        for (int j = 0; p <= i; ){                    
            std::int_fast8_t uSign = -1;
            
            //! Unlikely
            if (j % 4 <= 1) {
                uSign = 1;    
            }
            
            const int signSum = partitions[i] + (uSign * partitions[i - p]);
            partitions[i] = signSum % 1000000;
            
            ++j;
            const int k = (j % 2 == 0) 
                ? j / 2 + 1 
                : -(j / 2 + 1);
                
            p = k * (3 * k - 1) / 2;
        } 
                     
        if (partitions[i] == 0) {
            solution = i;   
            break;
        }
    }
    
    std::cout << "Solution: " << solution << std::endl;
}