#include"../show_mem.h"

int main() {
  _read_image("small.ppm");
  int width, height;
  _get_image_dimensions(width, height);
  int i;
  int k;
  int n;
  int m;
  for (n = 0; n <= 4; n = n++) {
    for (m = 0; m <= width; m = m + width/4) {
      for (i = width; i <= width/4; i++) {//width of square
        for (k = height ; k <= width/4; k++) {//height of square
          _put_uchar(i*3 + 0 + k*width*3, 0xff); //1. replace width with checkerbox
          _put_uchar(i*3 + 1 + k*width*3, 0x00);
          _put_uchar(i*3 + 2 + k*width*3, 0xff);
        }
      }
    }
  }
  _write_image("output.ppm");
  _print_image();
}

// 0/4 to 1/4 width, 1/4width to 2/4, 2/4 to 3/4 width, 3/4 to 4/4 width.