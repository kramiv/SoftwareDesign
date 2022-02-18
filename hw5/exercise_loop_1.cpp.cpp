#include"../show_mem.h"
int main() {
  _put_raw(0, ".");  // store a dot
  _put_raw(2, "\n"); // store newline
  int i;
  for (i = 100; i >= 0; i = i - 5) {
    _print_raw(0);  // print a dot
  }
  _print_raw(2);  // print newline
}