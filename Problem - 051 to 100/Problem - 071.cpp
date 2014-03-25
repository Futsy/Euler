#include <tuple>
#include <iostream>
#include <cmath>
#include <vector>

class FareySeq {
public:
    FareySeq(const int n) : N(n) {}
    int GetAnswer() const {
        //Next term Farey sequence
        double x1 = 0;
        double y1 = 1;
        double x2 = 1;
        double y2 = N;
        double x = 1;
        double y = N;
        double oldX = 0;

        while (y != 1.0) {
            oldX = x;
            oldY = y;

            x = std::floor((y1 + N) / y2) * x2 - x1;
            y = std::floor((y1 + N) / y2) * y2 - y1;
            if (static_cast<int>(x) == 3 && static_cast<int>(y) == 7)
                return oldX;
            x1 = x2, x2 = x, y1 = y2, y2 = y;
        }
        return -1;
    }

private:
    int N;
};

int main(){
    FareySeq f(1000000);
    std::cout << "Solution: " << f.GetAnswer() << std::endl;
}
