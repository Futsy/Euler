#include "LargeInt.h"

class Formula {
public:
    Formula(int a, int b, int c, const LargeInt& x, const LargeInt& y)
        : x(x), y(y), a(a), b(b), c(c) {}
    int GetA() const {
        return a;
    }
    int GetB() const {
        return b;
    }
    int GetC() const {
        return c;
    }
    const LargeInt& GetX() {
        return x;
    }
    const LargeInt& GetY() {
        return y;
    }
private:
    LargeInt x;
    LargeInt y;
    int a;
    int b;
    int c;
};

LargeInt Pell(int number) {
    const int sqrtN = sqrt(number);
    const int m = number - std::pow(sqrtN,2);

    //Break on squares
    if (!m) {
        return LargeInt::zero;
    }

    //Euclid alg
    Formula f1(1 + 2 * sqrtN - m, 2 * (m - sqrtN), m, 1, 1);
    while (true) {
        if (f1.GetA() == 1 && f1.GetB() == 0 && f1.GetC() == number) {
            break;
        }
        f1 = (f1.GetA() < (f1.GetB() + f1.GetC())) ?
            Formula(f1.GetA(), f1.GetB() - 2 * f1.GetA(), f1.GetC() + f1.GetB() - f1.GetA(), f1.GetX() + f1.GetY(), f1.GetY()) :
            Formula(f1.GetA() - f1.GetB() - f1.GetC(), f1.GetB() + 2 * f1.GetC(), f1.GetC(), f1.GetX(), f1.GetY() + f1.GetX());
    }
    return f1.GetX();
}

int main() {
    int solution = 0;
    LargeInt high = 0;

    for (int i = 2; i <= 1000; i++) {
        const LargeInt tCurrent = Pell(i);

        if (tCurrent > high) {
            high = tCurrent;
            solution = i;
        }
    }

    std::cout << "Solution: " << solution << std::endl;
}
