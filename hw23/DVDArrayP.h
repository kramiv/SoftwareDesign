#ifndef _DVDArrayP_H_
#define _DVDArrayP_H_
#include<iostream>
#include "DVD0.h"
//line 22: it uses DVD, so it needs to reference DVD.h for that

class DVDArrayP {
    int size;//# of pointer to DVD in elt
    DVD** elt;//points to a pointer: a pointer then can be assigened to DVD
public:
    static int Default_Size;//class variable = "static ..."
    DVDArrayP(int sz);
    DVDArrayP();
    DVDArrayP(const DVDArrayP &d);
    DVDArrayP &operator=(const DVDArrayP &d);
    void display();
    ~DVDArrayP();
    int getSize() {
        return size;
    }
// (arr1 = arr2)[0] = d2;
    DVD &operator[](int i);
};

#endif