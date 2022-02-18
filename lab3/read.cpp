//need to debug "unable to open image 'output.ppm': no such file or directory"
//imported images from lab 1 and ran: line 14 "may be used uninitialized in this function: output is segmentation fault (core dumped)

#include <iostream>
#include"../show_mem.h"

struct Pixel {
    char red, green, blue;
};

int main() {
    Pixel **image;//declare variable 'image' of correct type
    int width, height;
    _get_image_dimensions("small.ppm", width, height);
    _read_image("small.ppm", reinterpret_cast<char **>(image), width, height);
    // may be used uninitialized in this function: output is segmentation fault (core dumped)
    image = new Pixel*[height];//dynamically allocate for the pointers to scanlines
    for (int i = 0; i < height; i++) {
        image[i] = new Pixel[width];
    }
    image[0][0].green = 0;//make first pixel red
    image[0][0].red = 255;//make first pixel red
    image[0][0].blue = 0;//make first pixel red
    Pixel p1;
    p1.red = p1.green = p1.blue = 17;
    std::cerr << image[0][1].green << "\n";//print out 'a'
        _write_image("output.ppm", reinterpret_cast<char **>(image), width, height);
    //line above stores image in a ppm file
    //arguments to function = filename, data set up, width + height
    //add to code before deallocating arrays
    for (int i = 0; i < height; i++) {
    delete [] image[i];
    }
    delete [] image;
    //WHAT THE FLIPPITY FROGS IT WORKED
    //where does the computer even get 'a' from?????
}
//I need to do this thing.
//  convert output.ppm output.png
//unable to open image 'output.ppm' - no such file or directory
//