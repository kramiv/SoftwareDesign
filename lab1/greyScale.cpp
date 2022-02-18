#include"../show_mem.h"
//Exercise 5: greyScale.cpp  Change the r, g, and b 
//color channels for every pixel to the average of 
//the original values.
//current flaw: everything turns to 0000000 000000 etc.
int main() {
  _read_image("small.ppm");
  int width, height;
  _get_image_dimensions(width, height);
  int total_bytes;
  int i;
  int r;
  int g;
  int b;
  int ave;
  int sum;
  for (total_bytes = width*height*3; i <= total_bytes; ++i) {
    r = _get_unsigned_char(3*i + 0);//get R
    g = _get_unsigned_char(3*i + 1);//get G
    b = _get_unsigned_char(3*i + 2);//get B
    sum = (r + b + g);//calculate average
    ave = (sum/3);
    _put_unsigned_char(3*i + 0, ave);
    _put_unsigned_char(3*i + 1, ave);
    _put_unsigned_char(3*i + 2, ave);
  }
    _print_image();
    _write_image("output.ppm");
}