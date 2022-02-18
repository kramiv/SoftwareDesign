#include<iostream>
int main() {
  int arr[5] = {2, 3, 5, 7, 11};
  //for (int i = 0; i < 5; ++i)
  for (int &x : arr)
  x = 19;
  for (int x : arr)
  std::cerr << x << std::endl;
  //std::cerr << arr[i] << std::endl;
  for (auto x : arr)
  std::cerr << '\n' << x << std::endl;
}
