#include"../react.h"

int main() {
  init();

  add_yaml("hello.yaml");
  _put_raw(0, "abcd");  // null byte appended automatically
  _put_raw(5, "zyx");

  quit();
}
