#include<iostream>
void f(short *a, short *b) {
    short k[1] = {3};
    short *c;
    c = &k[1];
    a = b;
    b = c;
    a = c;//check

}

int main() {
    short g[2] = {1, 2};
    short *p0, *p1;
    p0 = &g[0];
    p1 = &g[1];
    std::cerr << *p0 << *p1;
    f(p0, p1);
    std::cerr << *p0 << *p1;

}