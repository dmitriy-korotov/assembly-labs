#include <iostream>

extern "C" int Calculate(int a, int b);

int main() {
    int a = 5;
    int b = 4;

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "res = " << Calculate(a, b) << std::endl;

    return 0;
}