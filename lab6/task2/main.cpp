#include <iostream>

extern "C" double Calculate(double a, double b);

int main() {
    double a = 5.5555;
    double b = 2.2222;

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "res = " << Calculate(a, b) << std::endl;

    return 0;
}