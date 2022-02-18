#include<iostream>
#include"../show_mem.h"
//make a new int using i1 and i2, and then get the length, and for
//that length, transfer it to the new location j.
int concatenate(int i1, int i2, int j) {
  // please fill in some code here
  int len = 0;
  char d = _get_char(i1 + len);//let's say "from" is 2
  while(0 != d) {//reach end of string
    ++len;//get length of string
    d = _get_char(i1 + len);//d = 4
  }
  int c;
  for (int i = 0; i <= len; ++i) {//len = 2: "hi"
    c = _get_char(i1 + i);//get char from 2,3,4
    _put_char_()
    ///I want to ask about this later, but I'm not sure how to 
    //actually concatenate the two strings without them overwriting 
  }
}

// I need to modify this based on the earlier code, but I can't figure
//that out.
//what assignment is sum100.cpp?
int main() {
  _put_raw(1, "hi");
  if (length(1) == 2) 
    std::cerr << "yes" << std::endl;
  else
    std::cerr << "no" << std::endl;
}
