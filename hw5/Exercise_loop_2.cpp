#include"../show_mem.h"
int main() {
  _put_raw(0, ".");  // store a dot
  _put_raw(2, "\n"); // store newline
  int n = 1;
  while (n < 100; n >= 0; n = 2*n ) {
    _print_raw(0);  // print a dot
  }
  _print_raw(2);  // print newline
}