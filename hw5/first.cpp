#include"../show_mem.h"

int main() {
  char a = 'H';
  _put_raw(0, "hello world!\n");
  _put_char(0, a);
  _print_raw(0);
}
