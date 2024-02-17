#include <iostream>
#include <bitset>
#include <climits>



void viewPointer(void* _ptr) noexcept
{
    char* p_char = reinterpret_cast<char*>(_ptr);
    unsigned short* p_ushort = reinterpret_cast<unsigned short*>(_ptr);   
    double* p_double = reinterpret_cast<double*>(_ptr);

    std::printf("P: %p \n", _ptr);
    std::printf("P1: %p \n", p_char);
    std::printf("P2: %p \n", p_ushort);
    std::printf("P3: %p \n", p_double);

    std::puts("\n");
    
    std::printf("P1 + 1: %p \n", p_char + 1);
    std::printf("P2 + 1: %p \n", p_ushort + 1);
    std::printf("P3 + 1: %p \n", p_double + 1);
}



void printPointer(void* _ptr) noexcept
{
    char* p_char = reinterpret_cast<char*>(_ptr);
    unsigned short* p_ushort = reinterpret_cast<unsigned short*>(_ptr);   
    double* p_double = reinterpret_cast<double*>(_ptr);

    std::printf("P1: %02X \n", *p_char);
    std::printf("P2: %08X \n", *p_ushort);
    std::printf("P3: %016X \n", *p_double);

    std::puts("\n");
    
    std::printf("P1 + 1: %02X \n", *(p_char + 1));
    std::printf("P2 + 1: %08X \n", *(p_ushort + 1));
    std::printf("P3 + 1: %016X \n", *(p_double + 1));
}



void printDump(void* _ptr, size_t _n) noexcept
{
    unsigned char* data = reinterpret_cast<unsigned char*>(_ptr);
    for (size_t i = 0; i < _n; i++)
        printf("%02hhX ", *(data + i));
    std::puts("\n");
}


/*
void print16(void* _ptr) noexcept
{
    unsigned short* p = reinterpret_cast<unsigned short*>(_ptr);
    std::printf("h: %04X ", *p);
    std::cout << "b: " << std::bitset<16>(*p) << " ";
    std::printf("u: %05u ", *p);

    short* p2 = reinterpret_cast<short*>(_ptr);
    std::printf("h: %04hX ", *p2);
    std::cout << "b: " << std::bitset<16>(*p2) << " ";
    std::printf("d: %06d ", *p2);

    std::cout << std::endl;
}
*/

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



void print64(void* _ptr) noexcept
{
    unsigned long long* p = reinterpret_cast<unsigned long long*>(_ptr);
    std::printf("h: %016llX ", *p);
    std::cout << "b: " << std::bitset<64>(*p) << " ";
    std::printf("u: %020llu ", *p);

    long long* p2 = reinterpret_cast<long long*>(_ptr);
    std::printf("d: %020lld ", *p2);

    double* p3 = reinterpret_cast<double*>(_ptr);
    std::printf("f: %013.2llf ", *p3);
    std::printf("fe: %06lle ", *p3);

    std::cout << std::endl;   
}



int main(int _argc, char* _argv[])
{
    std::puts("\nTask 1\n");

    double a = 78;
    viewPointer(&a);

    std::puts("\nTask 2\n");

    long long b = 0x1122334455667788;
    printPointer(&b);

    std::puts("\n");

    char c[] = "0123456789abcdef";
    printPointer(&c);

    std::puts("\nTask 3\n");

    std::puts("int = 4:\n");
    int d = 4;
    printDump(&d, 4);

    std::puts("int[3] = {4, 6, 1}:\n");
    int arr[] = { 4, 6, 1 };
    printDump(&arr, 12);

    std::puts("double = 54.12:\n");
    double f = 54.12;
    printDump(&f, 8);

    std::puts("\nTask 4\n");

    unsigned short a1 = 0;
    unsigned short a2 = UINT16_MAX;
    short a3 = INT16_MIN;
    short a4 = INT16_MAX;
    unsigned short x = 5;
    short y = -5;
    
    std::puts("unsigned short MIN");
    print16(&a1);
    std::puts("unsigned short MAX");
    print16(&a2);
    std::puts("short MAX");
    print16(&a3);
    std::puts("short MAX");
    print16(&a4);
    std::puts("x");
    print16(&x);
    std::puts("y");
    print16(&y);

    std::puts("\nTask 5\n");

    unsigned int b1 = 0;
    unsigned int b2 = UINT32_MAX;
    int b3 = INT32_MIN;
    int b4 = INT32_MAX;
    unsigned int x2 = 5;
    int y2 = -5;
    int z2 = 0xFF007100;
    float x3 = 5;
    float y3 = -5;
    float z3 = 0xFF007100;

    std::puts("unsigned int MIN");
    print32(&b1);
    std::puts("unsigned int MAX");
    print32(&b2);
    std::puts("int MAX");
    print32(&b3);
    std::puts("int MAX");
    print32(&b4);
    std::puts("x");
    print32(&x2);
    std::puts("y");
    print32(&y2);
    std::puts("z");
    print32(&z2);
    std::puts("x flaot");
    print32(&x3);
    std::puts("y float");
    print32(&y3);
    std::puts("z float");
    print32(&z3);

    std::puts("\nTask 6\n");

    unsigned long long c1 = 0;
    unsigned long long c2 = UINT64_MAX;
    long long c3 = INT64_MIN;
    long long c4 = INT64_MAX;
    unsigned long long x4 = 5;
    long long y4 = -5;
    long long z4 = 0xFF007100;
    double x5 = 5;
    double y5 = -5;
    double z5 = 0xFF007100;

    std::puts("unsigned long long MIN");
    print64(&c1);
    std::puts("unsigned long long MAX");
    print64(&c2);
    std::puts("long long MAX");
    print64(&c3);
    std::puts("long long MAX");
    print64(&c4);
    std::puts("x");
    print64(&x4);
    std::puts("y");
    print64(&y4);
    std::puts("z");
    print64(&z4);
    std::puts("x double");
    print64(&x5);
    std::puts("y double");
    print64(&y5);
    std::puts("z double");
    print64(&z5);

    return 0;
}