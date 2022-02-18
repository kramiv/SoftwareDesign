#include"../show_mem.h"
//write out stuff by hand, and then note that 
//i needs to be assigned a starting value as well
//as an ending value
int main() {
  _read_image("small.ppm");
  int width, height;
  _get_image_dimensions(width, height);

  int rr;
  int rg;
  int rb;
  int i;
  int bytes;
  int interval;
  //in small.ppm, width = 11.
  for (bytes = width*3; i < width; i++) {
    for (interval = 0; interval < height; interval = interval +2) {
      rr = _get_uchar(3*i + 0);
      rg = _get_uchar(3*i + 1);
      rb = _get_uchar(3*i + 2);
      _put_uchar(3*i + 0 + interval*bytes, rr);
      _put_uchar(3*i + 1 + interval*bytes, rg);
      _put_uchar(3*i + 2 + interval*bytes, rb);
    }
  }

  _print_image();
  _write_image("output.ppm");
}

//I could use the height of the image to copy onto even rows
//using the % function
//row 0, 2, 4, 6: for row % 2 = 0