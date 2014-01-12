#include <iostream>

class DateType {
public:
    int year = 1901;
    int month = 0;
    int day = 0;
};

int main () {
    const int upper = 2000;
    DateType dat;
    
    int solution = 0;

    for (; dat.year <= upper; dat.year++) {
        for (int j = 1; j <= 12; j++) {
            const bool specialCase = dat.year % 400 == 0 || (dat.year % 100 != 0 && dat.year % 4 == 0);
            
            switch (j) {
            case 4:
            case 6:
            case 9:
            case 11:
                dat.month = 30;
                break;
            case 2:
                if (specialCase) {
                    dat.month = 29;
                } 
                else {
                    dat.month = 28;
                }
                break;
            default:
                dat.month = 31;            
            }
        
            if (dat.day % 7 == 0) {
                solution++;
            }
            dat.day += dat.month;
        }
    }

    std::cout << "Solution: " << solution << std::endl;
}