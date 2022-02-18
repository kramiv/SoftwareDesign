//need to debug "unable to open image 'output.ppm': no such file or directory"
//see exercise 11 below: i need to go over and check
//that it makes sense.
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
    image = new Pixel*[height];//dynamically allocate for the pointers to scanlines
    for (int i = 0; i < height; i++) {
        image[i] = new Pixel[width];
    }//create it.
    //edit it: exercise_12:
    for (int i = 0; i < height; i++) {//copy while i = 0
        for (int j = 0; j < height; j++) {
            if (j % 2 == 0) {
                for (int k = 0; k < width; k++) {
                    image[i+j*width][k].red = image[i][k].red;
                    image[i+j*width][k].green = image[i][k].green;
                    image[i+j*width][k].blue = image[i][k].blue;
                }
            }
        }
    }

    //Pixel p1;
    //p1.red = p1.green = p1.blue = 17;
    //std::cerr << image[0][1].green << "\n";//print out 'a'
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
//convert output.ppm output.png
//unable to open image 'output.ppm' - no such file or directory