#include"../show_mem.h"

int main() {
  _read_image("tiny.ppm");

  int width, height;
  _get_image_dimensions(width, height);

  _put_unsigned_char(0, 0x00);
  _put_unsigned_char(1, 0xff);
  _put_unsigned_char(2, 0x00);
  _print_image();
  //RGB per pixel: R,G,B = total of 3 bytes. To get to bottom right,
  //you want the total # of pixels * 3 pixels per byte
  //for total number of bytes. Bottom right byte will be
  //3*length*width. This - 3 for R, -2 for G, -1 for B

  _write_image("output.ppm");
}