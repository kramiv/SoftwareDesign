 //Use a loop to make a sequence of bright purple 
 //pixels (0xff, 0x00, 0xff) on the top scanline of the
 // image that stretches to one quarter the width of 
 //the image, like this:
 #include"../show_mem.h"

int main() {
  _read_image("small.ppm");
  int width, height;
  _get_image_dimensions(width, height);
  int pwidth;
  pwidth = width/4;
  int i;
  for (i = 0; i < pwidth; i++) {
    _put_uchar(i*3 + 0, 0xff);
    _put_uchar(i*3 + 1, 0x00);
    _put_uchar(i*3 + 2, 0xff);
    }
  _print_image();
  _write_image("output.ppm");
}//  for (heightinterval = 0; heightinterval < 48; heightinterval++) {