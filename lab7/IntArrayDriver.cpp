//left off on exercise 11. waiting for piazza response.
#include "IntArray.h"
int x = 0;

int main() {
  IntArray arr1, arr2(3);
  std::cerr << "arr1 has size " << arr1.getSize() << std::endl;
  arr2.display(); std::cerr << std::endl;
 
  arr2[1] = 24;
  arr2.display(); std::cerr << std::endl;
  arr2[389]; // should display an error, but not crash
 
  IntArray arr3(arr2);
  arr3.display();
  arr1 = arr3;
  arr1.display();
  arr2[2] = 63;
  (arr1 = arr2)[0] = -99;
  arr1.display();
}
