#include"../show_mem.h"

int main() {
  _read_image("big.ppm");
  int width, height;
  _get_image_dimensions(width, height);
  int pwidth;
  pwidth = width/4;
  int i;
  int k;
  int pheight;
  pheight = height/4;
  for (i = 0; i < pwidth; i++) {
    for (k=0; k < pheight; k++){
    _put_uchar(i*3 + 0 + k*width*3, 0xff);
    _put_uchar(i*3 + 1 + k*width*3, 0x00);
    _put_uchar(i*3 + 2 + k*width*3, 0xff);
    }
  }
  _write_image("output.ppm");
}