#include <iostream>
#include <cmath>
#include <set>

int main () {
    std::set<double> powers;
    
    for (int i = 2; i <= 100; i++) {
        for (int j = 2; j <= 100; j++) {
            powers.insert(std::pow(i,j));   
        }
    }
    
    //Sorting doesn't change anything
    std::cout << "Solution: " << powers.size() << std::endl;
}