#ifndef _IntArray_H_
#define _IntArray_H_
#include<iostream>

class IntArray {
    int size;//number of ints in the array
    int *elt;//star before elt
    static int DEFAULT_SIZE;
public:
//constructor:
    IntArray(int sz);
//default constructor:
    IntArray();
//copy constructor:
    IntArray(const IntArray &d);
//destructor:
    ~IntArray() {
        delete [] elt;
    }
//methods
    int getSize() {
        return size;
    }
    void display();
    IntArray &operator=(const IntArray &arr);
    int &operator[](int i);
};

#endif  // _IntArray_H_
