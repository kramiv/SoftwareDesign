#include"../show_mem.h"
//this page is for printing stripes
int main() {
  _read_image("small.ppm");
  int width, height;
  _get_image_dimensions(width, height);

  int rr;
  int rg;
  int rb;
  int i;
  int bytes;
  //in small.ppm, width = 11.
  for (bytes = width*3; i < width; i++) {
    rr = _get_uchar(3*i + 0);
    rg = _get_uchar(3*i + 1);
    rb = _get_uchar(3*i + 2);
    _put_uchar(3*i + 0 + bytes, rr);
    _put_uchar(3*i + 1 + bytes, rg);
    _put_uchar(3*i + 2 + bytes, rb);
  }

  _print_image();
  _write_image("output.ppm");
}