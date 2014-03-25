#include <iostream>
#include <cmath>

class FareySeq {
public:
    FareySeq(const int n) : N(n) {}
    int GetAnswer() const {
        bool startCounting = false;
        int count = 0;
    
        //Next term Farey sequence
        double x1 = 0;
        double y1 = 1;
        double x2 = 1;
        double y2 = N;
        double x = 1;
        double y = N;
    
        while (y != 1.0) {
            x = std::floor((y1 + N) / y2) * x2 - x1;
            y = std::floor((y1 + N) / y2) * y2 - y1;
            
            if (x < y && x > 0.1) {
                //Check for 1/2
                if (x == 1 && y == 2) 
                    return count;    
                
                //Increment if 1/3 passed
                if (startCounting)
                    count++;
                
                //Check for 1/3
                if (x == 1 && y == 3)
                    startCounting = true;    
            }
            x1 = x2, x2 = x, y1 = y2, y2 = y;
        }
        return -1;
    }
    
private:
    int N;
};

int main(){
    FareySeq f(12000);
    std::cout << "Solution: " << f.GetAnswer() << std::endl;
}