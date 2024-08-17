#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

int main() {
    double r;
    std::cout << std::fixed; // 소숫점을 고정시키겠다!
    std::cout.precision(6); // 6자리까지 표현하겠다!
    std::cin >> r;

    std::cout << pow(r, 2) * M_PI << "\n";
    std::cout << pow(r, 2) * 2;

    return 0;
}