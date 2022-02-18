

#include <iostream>
#include"../show_mem.h"

struct Pixel {
    char red, green, blue;
};

int main() {
  Pixel p1;
  p1.red = p1.green = p1.blue = 17;
  int n = p1.red;  // convert to int, prior to printing
  std::cerr << n << "\n";
}
//1 scanline = 3 pixels (Pixel = scanline). 0, 1, and 2 of 
//each scanline = allows access to each pixel.
//example: image[1][1].red

//scanline = array of pixels
//image as a whole = pointer to an array of pointers
//to scanlines