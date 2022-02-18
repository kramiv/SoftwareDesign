#include<iostream>
#include"../show_mem.h
void copy_bytes(int from, int to) {//why is it called "void"?
  int len = 0;
  char d = _get_char(from + len);//let's say "from" is 2
  while(0 != d) {//reach end of string
    ++len;//get length of string
    d = _get_char(from + len);//d = 4
  }
  // len is the number of non-null bytes to copy
  for (int i = 0; i <= len; ++i) {//len = 2: "hi"
    char c = _get_char(from + i);//get char from 2,3,4
    _put_char(to + i, c);//say we're putting it in 5: put c's
    //characters in 5+0, 5+1, 5+2
  }
}

int main() {
  _put_raw(1, "hi");  // add some data to _global_mem
  copy_bytes(1, 5);   // call the function
  std::cerr << "expecting: hi" << std::endl;
  _print_raw(5);    // print out the result
  _print_newline();
}
