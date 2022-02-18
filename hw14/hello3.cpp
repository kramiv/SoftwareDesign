#include"../react.h"

int main() {
  init();

  add_yaml("hello.yaml");
  if (just_starting()) {
    _put_raw(0, "abcd");  // null bye appended automatically
    _put_raw(5, "zyx");
  } else {
    char *s = &(_global_mem[1]);
    _put_raw(5, s);
  }

  quit();
}
