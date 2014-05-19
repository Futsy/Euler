/**
 * Compile-time solution
 */
 

constexpr unsigned int SumMulti(int n) {
    return n * (999 / n * (999 / n + 1)) / 2;
}
 
int main() {
    return SumMulti(3) + SumMulti(5) - SumMulti(15);
}
