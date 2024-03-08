#include <iostream>
#include <bitset>
#include <climits>

void print16(void* _ptr) noexcept
{
    unsigned short* p = reinterpret_cast<unsigned short*>(_ptr);
    std::printf("h: %04X ", *p);
    std::cout << "b: " << std::bitset<16>(*p) << " ";
    std::printf("u: %05u ", *p);

    short* p2 = reinterpret_cast<short*>(_ptr);
    std::printf("d: %06d ", *p2);

    std::cout << std::endl;
}

void print32(void* _ptr) noexcept
{
    unsigned int* p = reinterpret_cast<unsigned int*>(_ptr);
    std::printf("h: %08X ", *p);
    std::cout << "b: " << std::bitset<32>(*p) << " ";
    std::printf("u: %010u ", *p);

    int* p2 = reinterpret_cast<int*>(_ptr);
    std::printf("d: %010d ", *p2);

    float* p3 = reinterpret_cast<float*>(_ptr);
    std::printf("f: %5.2f ", *p3);
    std::printf("fe: %016e ", *p3);

    std::cout << std::endl;   
}


void task1() {
    short m = 
}

int main() {
    std::cout << "hello";
}