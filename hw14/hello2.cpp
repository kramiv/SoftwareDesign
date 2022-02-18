#include"../react.h"

int main() {
  init();

  add_yaml("hello.yaml");
  for (int n = 0; n < 4; n++) {
    if ('A' == _global_mem[n]) {
        _put_raw(5, "Detected an A!");
        } else {
            _put_raw(0, "abcd");
            _put_raw(5, "zyx");
        }
  }


  quit();
}
