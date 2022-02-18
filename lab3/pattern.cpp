//need to debug "unable to open image 'output.ppm': no such file or directory"

#include <iostream>
#include"../show_mem.h"

struct Pixel {
    char red, green, blue;
};

int main() {
    Pixel **image;//declare variable 'image' of correct type
    int height = 16;
    int width = 16;
    image = new Pixel*[height];//dynamically allocate for the pointers to scanlines
    for (int i = 0; i < height; i++) {
        image[i] = new Pixel[width];
    }
    //exercise_5:
    for (int i = 0; i < height; i++) {
        for (int k = 0; k < width; k++) {
            if (i % 5 == 0) {
                image[i][k].red = i*50;
            } else {
                continue;
            } if (k % 5 == 0) {
                image[i][k].green = k*50;
                if (i % 5 == 0) {
                    if (i*k < 255) {
                        image[i][k].blue = i*k;
                    } else {
                    image[i][k].blue = 255;
                    }
                }
            }
        }
    }



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