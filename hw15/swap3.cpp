#include<iostream>

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void swap(float &a, float &b) {
  float tmp = a;
  a = b;
  b = tmp;
}

void swap(double &a, double &b) {
    double tmp = a;
    a = b;
    b = tmp;
}

int main() {
  // int n = 3, m = 4;
  double x = 5, y = 6;
  swap(x, y);
  std::cerr << x << ' ' << y << '\n';  // outputs 6 5
}
