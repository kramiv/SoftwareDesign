#include"../show_mem.h"

int main() {
  _read_image("small.ppm");
  int width, height;
  _get_image_dimensions(width, height);
  int i;
  int k;
  //swapped out in for loops pwidth, pheight chronologically
  for (i = 3; i < 8; i++) {//just changed where it started
    for (k = 3; k < 8; k++){
    _put_uchar(i*3 + 0 + k*width*3, 0xff);
    _put_uchar(i*3 + 1 + k*width*3, 0x00);
    _put_uchar(i*3 + 2 + k*width*3, 0xff);
    }
  }
  _write_image("output.ppm");
}