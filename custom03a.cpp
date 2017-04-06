#include <iostream>

// When using C++ you should encapsulate extern void my_js(); in an extern "C" {} block to prevent C++ name mangling:
extern "C" {
    int mytest(int);
}

int mytest(int x) {
    return x * x + 10;
}

extern "C" {
    int mytest2(int a, int b){
        return a * 2 + b * 3;
    }
}
