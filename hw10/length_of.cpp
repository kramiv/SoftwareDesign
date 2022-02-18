#include<iostream>// for cerr?
using namespace std;
#include<fstream>// pulling files from soemwhere else?
#include<string.h>

int x;
int *xx = &x;

int length_of(int *xx) {
int len;
  len = 0;
  char *xx = getchar(*xx + len);//let's say "from"
  while(0 != *xx) {//reach end of string
    ++len;//get length of string
    char *xx = getchar(len);//d = 4
  }
  char length;
  *xx = length;
  return(length);
}