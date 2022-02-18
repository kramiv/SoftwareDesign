#include<iostream>
short global_1 = 3, global_2 = 4;

short &get_first() { 
  return global_1; 
}

short &get_one(int i) {
    if (i == 1) {
        return global_1;
    } else {
        return global_2;
    }
}

int main() {
  get_first() = 5;  // ok
  std::cerr << global_1 << '\n' << std::endl;  // outputs 5
  get_one(1) = 3;
  std::cerr << global_1 << " (changed value from 5) " << '\n' << std::endl;
}
