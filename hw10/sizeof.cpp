//Write a program sizeof.cpp that uses the sizeof operator 
//to discover the number of bytes needed by short, int, and 
//double variables (and print out this information).  For 
//example, std::cerr << sizeof(short) << std::endl;  Then 
//extend the program to show the number of bytes needed for 
//a pointer to a short, a pointer to an int, and a pointer 
//to a pointer to a double.


#include<iostream>// for cerr?
using namespace std;
#include<fstream>// pulling files from soemwhere else?
#include<string.h>// find stringlength of string
int x = 1;
short y = 2;
double z = 3;

int *xx = &x;//pointer to a short
short *yy = &y;
double *zz = &z;

int main() {
    std::cerr << sizeof(int) << std::endl;
    std::cerr << sizeof(short) << std::endl;
    std::cerr << sizeof(double) << std::endl;
    std::cerr << sizeof(*xx) << std::endl;
    std::cerr << sizeof(*yy) << std::endl;
    std::cerr << sizeof(*zz) << std::endl;


}