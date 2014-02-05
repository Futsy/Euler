#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <functional>
#include <type_traits>
#include <algorithm>

template <typename T>
class Generator {
private:
    using rTyp = std::vector<std::vector<T>>;
    using sTyp = std::vector<T>;
private:
    //Shape structure
    std::vector<std::pair<int,std::function<T(const T)>>> shapeMap = {
        std::make_pair(0,[=](const int n){ return (n * (n + 1)) / 2;}),
        std::make_pair(1,[=](const int n){ return n * n;}),
        std::make_pair(2,[=](const int n){ return (n * (3 * n - 1)) / 2;}),
        std::make_pair(3,[=](const int n){ return (n * (2 * n - 1));}),
        std::make_pair(4,[=](const int n){ return (n * (5 * n - 3)) / 2;}),
        std::make_pair(5,[=](const int n){ return (n * (3 * n - 2));})
    };
public:
    Generator() {
        static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value,"This only works with numbers");
    }
    rTyp CreateShapes(const int digits) {
        return {
            Shape(digits,0), Shape(digits,1), Shape(digits,2),
            Shape(digits,3), Shape(digits,4), Shape(digits,5)
        };
    }
private:
    sTyp Shape(const int digits, const int shape) {
        sTyp sType;

        for (T i = 1;;i++) {
            const T result = (shapeMap[shape].second)(i);
            if (i != 1 && std::to_string(result).size() > digits) {
                break;
            }
            if (result >= 1000) {
                sType.push_back(result);
            }
        }
        return sType;
    }
};

template <typename T>
class Solver {
private:
    using rTyp = std::vector<std::vector<T>>;
    using sTyp = std::vector<T>;
    Generator<T> generator;
public:
    Solver() : generator() {}
    T Solve(const int digits);
    T CyclicSequence(rTyp start);
private:
    bool Check(T t1, T t2);
};

template <typename T>
T Solver<T>::Solve(const int digits) {
    return CyclicSequence(generator.CreateShapes(digits));
}

template <typename T>
bool Solver<T>::Check(T t1, T t2) {
    const std::string e1 = std::to_string(t1);
    const std::string e2 = std::to_string(t2);

    return (e1[2] == e2[0] && e1[3] == e2[1]);
}

template <typename T>
T Solver<T>::CyclicSequence(rTyp start) {
    std::vector<int> shapes[6] = { start[0], start[1], start[2], start[3], start[4], start[5] };
    int options[6] = { 0, 1, 2, 3, 4, 5 };

    //Very readable code right here
    do {
        for (int i = 0; i < shapes[options[0]].size(); i++) {
            for (int j = 0; j < shapes[options[1]].size(); j++) {
                if (Check(shapes[options[0]][i],shapes[options[1]][j])) {
                    for (int k = 0; k < shapes[options[2]].size(); k++) {
                        if (Check(shapes[options[1]][j],shapes[options[2]][k])) {
                            for (int l = 0; l < shapes[options[3]].size(); l++) {
                                if (Check(shapes[options[2]][k],shapes[options[3]][l])) {
                                    for (int m = 0; m < shapes[options[4]].size(); m++) {
                                        if (Check(shapes[options[3]][l],shapes[options[4]][m])) {
                                            for (int n = 0; n < shapes[options[5]].size(); n++) {
                                                if (Check(shapes[options[4]][m],shapes[options[5]][n]) && Check(shapes[options[5]][n],shapes[options[0]][i])) {
                                                    return shapes[options[0]][i] + shapes[options[1]][j] +
                                                        shapes[options[2]][k] + shapes[options[3]][l] +
                                                        shapes[options[4]][m] + shapes[options[5]][n];
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    while (std::next_permutation(options, options + 6));
    return -1;
}

int main() {
    std::cout << "Solution: " << Solver<int>().Solve(4) << std::endl;
}
