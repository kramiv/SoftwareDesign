#include"../show_mem.h"
int main() {
  _read_image("tiny.ppm");
  int width, height;
  _get_image_dimensions(width, height);
  //set RGB set R,B to 0
  int total_bytes;
  int i;
  for (total_bytes = width*height*3; i <= total_bytes; ++i) {
    _put_unsigned_char(3*i + 0, 0x00);
  }
    _print_image();
    _write_image("output.ppm");
}