#include <iostream>
#include <cmath>
#include <vector>

int main()
{
    // Can just log(a) * b or log(log(b))*log(a)->log(log(a^b))
    auto largest = 0.0;
    auto result = 0u;
    
    for (unsigned i = 0; i < input.size() / 2; i++) {
        const auto toLog = log(input[i * 2]) * input[(i * 2) + 1];
        if (toLog > largest) {
            largest = toLog;
            result = i;
        }
    }
    std::cout << result + 1 << std::endl;
}
