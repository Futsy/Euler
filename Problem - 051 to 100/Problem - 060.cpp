#include <iostream>
#include <string>
#include <thread>
#include <vector>

const int rangeGuess = 20000;
int solution = rangeGuess * 10;

bool Prime(int number){
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

bool cat(const int first, const int second) {
    return !(Prime(std::stoi(std::to_string(first) + std::to_string(second)))
            && Prime(std::stoi(std::to_string(second) + std::to_string(first))));
}

void LowerBounds(const int i) {
    if (!Prime(i)) {
        return;
    }
    for (int j = i + 2; j < rangeGuess; j += 2) {
        if (!Prime(j) || cat(i,j)) {
            continue;
        }
        for (int k = j + 2; k < rangeGuess; k += 2) {
            if (!Prime(k) || cat(k,j) || cat(k,i)) {
                continue;
            }
            for (int l = k + 2; l < rangeGuess; l += 2) {
                if (!Prime(l) || cat(k,l) || cat(l,j) || cat(l,i)) {
                    continue;
                }
                for (int m = l + 2; m < rangeGuess; m += 2) {
                    if (!Prime(m) || cat(m,l) || cat(m,i) || cat(m,j) || cat(m,k)) {
                        continue;
                    }

                    const int sum = i + j + k + l + m;
                    if (sum < solution) {
                        solution = sum;
                    }
                }
            }
        }
    }
}

int main() {
    //5 loop bruteforce non-sieve, should use sieve to speed up
    //Currently checks: (20000^4 + 20) / 2 options
    //Multithreading Compiler flags: g++ -std=c++11 -O3 -fpermissive main.cpp && ./a.out
    const int firstGuess = 20;
    const int lowBound = 3;

    std::vector<std::thread> threads;

    for (int i = lowBound; i < firstGuess; i += 24) {
        for (int temp = 0; temp < 24; temp += 2) {
            threads.push_back(std::thread(LowerBounds,i + temp));
        }

        for (auto& e : threads) {
            e.join();
        }
    }

    std::cout << "Solution: " << solution << std::endl;
}
