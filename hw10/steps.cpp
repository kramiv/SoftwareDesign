#include<iostream>
using namespace std;
int i = 17;
double f = -4.2;
int *ip = &i;
double *fp = &f;

int f2 = 2.5;
double *fp = &f2;
int *ip = i*(*ip);

int func(int arg) {
  arg = arg + 2;
  return arg;
}

int funcp(int *argp) {
  *argp = (*argp) + 2;
  return *argp;
}

int main () {
  char array[] = "initial values:";
  char a[] = " i is ";
  char b[] = " *ip is ";
  char c[] = " f is ";
  char d[] = " *fp is ";
  char e[] = " f2 is ";

  cout << array << a << i << b << *ip << c << f << d << *fp << endl;
  i = i*3;
  *fp = (*fp)*1.5;
  char array2[] = "after multiplying: ";
  cout << array2 << a << i << b << *ip << c << f << d << *fp << endl;
  cout << array2 << a << i << b << *ip << c << f << d << *fp << e << f2 << endl;
  
  //return 0;
  //OR
  //std:cerr << i  "hi" << std::endl;
  //std::cerr << "Initial values: i is " i ", *ip is" *ip "f is" f ", *fp is" *fp << std::endl;
}
