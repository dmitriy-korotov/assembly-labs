#include <iostream>
#include <bitset>
#include <climits>

#define increment(it, format) \
    std::printf(format, it); \
    std::printf( "++ = "); \
    it++; \
    std::printf(format, it); \
    std::printf( "\n");



void print16(void* _ptr) noexcept
{
    unsigned short* p = reinterpret_cast<unsigned short*>(_ptr);
    std::printf("h: %04X     ", *p);
    std::cout << "b: " << std::bitset<16>(*p) << "                 ";
    std::printf("u: %05u      ", *p);

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
    std::printf("f: %13.2llf ", *p3);
    std::printf("fe: %06lle ", *p3);

    std::cout << std::endl;   
}


void task1() {
    printf("\n========== task 1 ========== \n\n");

    short m = 201;
    short n = -59;

    int s_m = m;
    unsigned int u_m = *reinterpret_cast<unsigned short*>(&m);

    int s_n = n;
    unsigned int u_n = *reinterpret_cast<unsigned short*>(&n);

    std::printf("        m=  ");
    print16(&m);
    std::printf("   (int)m=  ");
    print32(&s_m);
    std::printf("  (uint)m=  ");
    print32(&u_m);

    std::printf("\n");

    std::printf("        n=  ");
    print16(&n);
    std::printf("   (int)n=  ");
    print32(&s_n);
    std::printf("  (uint)n=  ");
    print32(&u_n);
}

void task2(short x) {
    short signed_multiply_2 = x * 2;
    std::printf("   signed *2=       ");
    print16(&signed_multiply_2);
    
    unsigned short unsigned_multiply_2 = (*reinterpret_cast<unsigned short*>(&x)) * 2u;
    std::printf("   unsigned *2=     ");
    print16(&unsigned_multiply_2);


    std::printf("\n");


    short signed_div_2 = x / 2;
    std::printf("   signed /2=       ");
    print16(&signed_div_2);
    
    unsigned short unsigned_div_2 = (*reinterpret_cast<unsigned short*>(&x)) / 2u;
    std::printf("   unsigned /2=     ");
    print16(&unsigned_div_2);


    std::printf("\n");


    short unsigned_mod_16 = (*reinterpret_cast<unsigned short*>(&x)) % 16u;
    std::printf("   unsigned %%16=    ");
    print16(&unsigned_mod_16);

    short unsigned_floor_16 = ((*reinterpret_cast<unsigned short*>(&x)) >> 4) << 4;
    std::printf("   unsigned floor=  ");
    print16(&unsigned_floor_16);


    std::printf("\n");


    short signed_shl = x << 1;
    std::printf("   signed shl=      ");
    print16(&signed_shl);
    
    unsigned short unsigned_shl = (*reinterpret_cast<unsigned short*>(&x)) << 1;
    std::printf("   unsigned shl=    ");
    print16(&unsigned_shl);


    std::printf("\n");


    short signed_shr = x >> 1;
    std::printf("   signed shr=      ");
    print16(&signed_shr);
    
    unsigned short unsigned_shr = (*reinterpret_cast<unsigned short*>(&x)) >> 1;
    std::printf("   unsigned shr=    ");
    print16(&unsigned_shr);


    std::printf("\n");


    unsigned short unsigned_and = (*reinterpret_cast<unsigned short*>(&x)) & 15u;
    std::printf("   unsigned &=      ");
    print16(&unsigned_and);
    
    unsigned short signed_and = x & -16;
    std::printf("   signed &=        ");
    print16(&signed_and);
}

void task2() {
    printf("\n========== task 2 ========== \n\n");

    printf("\n   ======== 201 ======== \n\n");
    task2(201);

    printf("\n   ======== -59 ======== \n\n");
    task2(-59);
}


unsigned int floor_to_64(unsigned int x) {
    return (x >> 6) << 6;
}

unsigned int ceil_to_64(unsigned int x) {
    return x + (-x & 0b111111u);
}

void print_floor_to_64(unsigned int x) {
    std::printf("   %d=   ", x);
    unsigned int floored = floor_to_64(x);
    print32(&floored);
}

void print_ceil_to_64(unsigned int x) {
    std::printf("   %d=   ", x);
    unsigned int ceiled = ceil_to_64(x);
    print32(&ceiled);
}

void task3() {
    printf("\n========== task 3 ========== \n\n");

    printf("\n   ======== Floor ======== \n\n");

    print_floor_to_64(128);
    print_floor_to_64(130);
    print_floor_to_64(190);
    print_floor_to_64(192);

    printf("\n   ======== Ceil ======== \n\n");

    print_ceil_to_64(128);
    print_ceil_to_64(130);
    print_ceil_to_64(190);
    print_ceil_to_64(192);
}

void task4() {
    printf("\n========== task 4 ========== \n\n");

    int m = 201;
    int n = -59;

    float a = 0;
    float b = 1;
    float c = 12345678;
    float d = 123456789;

    unsigned int min_u_int = 0u;
    unsigned int max_u_int = UINT32_MAX;
    int min_int = INT32_MIN;
    int max_int = INT32_MAX;

    increment(m, "%d");
    increment(n, "%d");

    std::printf("\n");

    increment(a, "%f");
    increment(b, "%f");
    increment(c, "%f");
    increment(d, "%f");

    std::printf("\n");

    increment(min_u_int, "%u");
    increment(max_u_int, "%u");

    increment(min_int, "%d");
    increment(max_int, "%d");
}


float absolute(float x) {
    unsigned int mask = 0xFFFFFFFFu ^ (1u << 31);

    unsigned int reinterpretedX = *reinterpret_cast<unsigned int*>(&x);

    unsigned int masked = reinterpretedX & mask;

    return *reinterpret_cast<float*>(&masked);
}

void printAbsolute(float x) {
    std::printf("|%f| = %f\n", x, absolute(x));
}

void task5() {
    printf("\n========== task 5 ========== \n\n");
    printAbsolute(-122203049);
    printAbsolute(-12);
    printAbsolute(0);
    printAbsolute(21);
}


void floatForward(int n) {
    float res = 0;
    for (int i = 1; i < n; i++) {
        res += 1.0f / i;
    }
    print32(&res);
}

void floatBackward(int n) {
    float res = 0;
    for (int i = n; i > 0; i--) {
        res += 1.0f / i;
    }
    print32(&res);
}

void doubleForward(int n) {
    double res = 0;
    for (int i = 1; i < n; i++) {
        res += 1.0 / i;
    }
    print64(&res);
}

void doubleBackward(int n) {
    double res = 0;
    for (int i = n; i > 0; i--) {
        res += 1.0 / i;
    }
    print64(&res);
}

void task6() {
    printf("\n========== task 6 ========== \n\n");

    printf("\n   ======== Float forward ======== \n\n");

    floatForward(1000);
    floatForward(1000000);
    floatForward(1000000000);

    printf("\n   ======== Float backward ======== \n\n");

    floatBackward(1000);
    floatBackward(1000000);
    floatBackward(1000000000);

    printf("\n   ======== Double forward ======== \n\n");

    doubleForward(1000);
    doubleForward(1000000);
    doubleForward(1000000000);

    printf("\n   ======== Double backward ======== \n\n");

    doubleBackward(1000);
    doubleBackward(1000000);
    doubleBackward(1000000000);
}

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
}