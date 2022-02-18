//fix

#include<iostream>
#include"../show_mem.h"

int main() {
    short *arr = reinterpret_cast<short *>(_global_mem + 20);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    std::cerr << arr[0] << std::endl;
    std::cerr << arr[1] << std::endl;
    std::cerr << arr[2] << std::endl;
}
