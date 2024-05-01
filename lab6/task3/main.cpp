#include <iostream>

extern "C" int Print(int a, int b, int c, int d, int e, int f, int g);

int main() {
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;
    int g = 7;

    auto res = Print(a, b, c, d, e, f, g);
    std::cout << "res = " << res << std::endl;

    return 0;
}