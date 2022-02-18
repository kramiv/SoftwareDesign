//Name: length
//1 Argument: a non-negative integer n, representing a position in 
//_global_mem
//Return: the length of the character sequence starting at n, that is,
// the the number of bytes preceding the null byte.
//Example: if the character sequence at index [1] is "hi", and 
//we call length(1); then the return value will be two.

///////I need to figure out how to make these all run.
///the command to make them run.

#include<iostream>
#include"../show_mem.h"

int length(int n) {
  // please fill in some code here
  int n = 0;
  int len;
  len = 0;
  char n = _get_char(n + len);//let's say "from" is 2
  while(0 != d) {//reach end of string
    ++len;//get length of string
    n = _get_char(len);//d = 4
  }
  int length;
  n = length;
  return(length);
}

int main() {
  _put_raw(1, "hi");
  if (length(1) == 2) 
    std::cerr << "yes" << std::endl;
  else
    std::cerr << "no" << std::endl;
}
