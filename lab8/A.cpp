#include<iostream>
int main() {
  int z = 3;
  auto w = z;
  std::cerr << w << std::endl;
  long x = 4;
  w = x;
  std::cerr << w << std::endl;
  
  auto &w2 = z;
  w2 = 5; 
  std::cerr << w2 << std::endl;  
  std::cerr << z << std::endl;

}
/*
Well, when we create a reference, you can imagine
from the memory diagram that we
are making something without a box.
Once the reference has been made, then we use it just like any other variable.
*/