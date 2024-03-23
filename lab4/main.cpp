#include <iostream>
#include <algorithm>



static constexpr size_t N = 5;



template <typename T>
void printArray(T* arr, size_t N, std::string arrayName = "") {
    std::cout << arrayName << ":" << std::endl;
    for (size_t i = 0; i < N; i++) {
        std::cout << std::hex << arr[i] << " ";
    }
    std::cout << std::endl;
}

void movShortByIndex(short* dest, int idx) {
    asm ("movw $16, %0":"=r"(dest[idx]):);
}

void movIntByIndex(int* dest, int idx) {
    asm ("movl %1, %0":"=r"(dest[idx]):"r"(16));
}

void movLongLongByIndex(long long* dest, int idx) {
    asm ("movq %1, %0":"=r"(dest[idx]):"r"(16ll));
}

void movLongLongTask2(long long* arr, size_t idx) {
    asm ("movq $-1, (%0, %1, 8)"::"r"(arr),"r"(idx));
}

void movTask3(long long* arr, size_t idx) {
    asm ("movb $0xBB, (%0, %1, 1)"::"r"(arr),"r"(idx));
}

void movTask4(long long* arr, size_t idx, long long* value) {
    long long tmp;
    asm ("movq (%1), %0":"=r"(tmp):"r"(value));
    asm ("movq %2, (%0, %1, 8)"::"r"(arr),"r"(idx),"r"(tmp));
}

void movTask5(long long* arr, size_t idx, long long* value) {
    long long tmp;
    asm ("movq %1, %0":"=r"(tmp):"r"(value));
    asm ("movq %2, (%0, %1, 8)"::"r"(arr),"r"(idx),"r"(tmp));
}

void movTask6(long long& z, long long& w, long long x, long long y) {
    asm ("movq %1, %0":"=r"(z):"r"(x));
    asm ("addq %1, %0":"+r"(z):"r"(y));
    asm ("movq %1, %0":"=r"(w):"r"(x));
    asm ("subq %1, %0":"+r"(w):"r"(y));
}

void movTask7(double* arr, double x, size_t i) {
    unsigned int C;
    asm("cpuid\n": "=c"(C): "a"(1):"ebx","edx");
    bool AVX_bit = (C & (1 << 28)) != 0;
    std::cout << "AVX: " << std::boolalpha << AVX_bit << std::endl;
    
    asm ("vmovsd %0, %%xmm2"::"rq"(x));
    asm ("vmovsd %xmm2, (%0, %1, 8)":"=rm"(arr):"r"(i));
}

void movTask8(double* arr, long long x, size_t i) {
    asm ("vcvtsi2sd %0, %%xmm1, %%xmm2"::"r"(x));
    asm ("vmovsd %xmm1, (%0, %1, 8)":"=rm"(arr):"r"(i));
}



int main(int _argc, char* _argv[])
{
    std::cout << "\nTASK 1\n" << std::endl;

    short Ms[N] = {};
    std::fill_n(Ms, N, 0xFADE);

    int Ml[N] = {};
    std::fill_n(Ml, N, 0xADE1A1DA);

    long long Mq[N] = {};
    std::fill_n(Mq, N, 0xC1A551F1AB1E);

    std::cout << "Before:" << std::endl;
    printArray(Ms, N, "Ms");
    printArray(Ml, N, "Ml");
    printArray(Mq, N, "Mq");

    movShortByIndex(Ms, 0);
    movIntByIndex(Ml, 1);
    movLongLongByIndex(Mq, 2);

    std::cout << "\nAfter:" << std::endl;
    printArray(Ms, N, "Ms");
    printArray(Ml, N, "Ml");
    printArray(Mq, N, "Mq");

    std::cout << "\nTASK 2\n" << std::endl;

    std::cout << "Before:" << std::endl;
    printArray(Mq, N, "Mq");

    movLongLongTask2(Mq, 3);

    std::cout << "\nAfter:" << std::endl;
    printArray(Mq, N, "Mq");

    std::cout << "\nTASK 3\n" << std::endl;

    std::cout << "Before:" << std::endl;
    printArray(Mq, N, "Mq");

    movTask3(Mq, 4);

    std::cout << "\nAfter:" << std::endl;
    printArray(Mq, N, "Mq");

    std::cout << "\nTASK 4\n" << std::endl;

    std::cout << "Before:" << std::endl;
    printArray(Mq, N, "Mq");

    long long* value = new long long(5ll);
    movTask4(Mq, 4, value);

    std::cout << "\nAfter:" << std::endl;
    printArray(Mq, N, "Mq");

    std::cout << "\nTASK 5\n" << std::endl;

    std::cout << "Before:" << std::endl;
    printArray(Mq, N, "Mq");

    movTask5(Mq, 4, value);
    delete value;

    std::cout << "\nAfter:" << std::endl;
    printArray(Mq, N, "Mq");

    std::cout << "\nTASK 6\n" << std::endl;
    long long z = 0;
    long long w = 0;
    std::cout << "Before:" << std::endl;
    std::cout << std::hex << "z = " << z << " w = " << w << std::endl;
    movTask6(z, w, 6ll, 4ll);

    std::cout << "\nAfter:" << std::endl;
    std::cout << std::hex << "z = " << z << " w = " << w << std::endl;

    std::cout << "\nTASK 7\n" << std::endl;

    float Mfs[N] = {};
    std::fill_n(Mfs, N, 5.0f / 3.0f);

    double Mfl[N] = {};
    std::fill_n(Mfl, N, 5.0 / 3.0);    

    std::cout << "Before:" << std::endl;
    std::cout.precision(10);
    printArray(Mfs, N, "Mfs");
    printArray(Mfl, N, "Mfl");

    movTask7(Mfl, 7.254, 1);

    std::cout << "\nAfter:" << std::endl;
    printArray(Mfs, N, "Mfs");
    printArray(Mfl, N, "Mfl");

    std::cout << "\nTASK 8\n" << std::endl;

    std::cout << "Before:" << std::endl;
    std::cout.precision(10);
    printArray(Mfs, N, "Mfs");
    printArray(Mfl, N, "Mfl");

    movTask7(Mfl, 7.254, 1);

    std::cout << "\nAfter:" << std::endl;
    printArray(Mfs, N, "Mfs");
    printArray(Mfl, N, "Mfl");

    return 0;
}