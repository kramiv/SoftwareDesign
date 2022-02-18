#include"../show_mem.h"
int main() {
  _read_image("small.ppm");
  int width, height;
  _get_image_dimensions(width, height);
  //set RGB set R,B to 0
  int total_bytes;
  int i;
  int g;
  for (total_bytes = width*height*3; i <= total_bytes; ++i) {
    g = _get_unsigned_char(3*i + 1);//get G
    if (g < 127)//
      _put_unsigned_char(3*i + 1, 2*g);
      else
      _put_unsigned_char(3*i + 1, 255);
  }
    _print_image();
    _write_image("output.ppm");
}