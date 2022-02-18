//line 32: "image" part - not sure if correct.
#include<iostream>
#include<fstream>
//add pixel struct.
struct Pixel {
    char red, green, blue;
};

class Image {//a digital image with 3 color channels.
    int width;
    int height;
    int depth;
    Pixel** data;//points to array of pointers
public:
    //constructors - unedited
    Image(int w, int h) {//dynamically allocate Pixels for width, height
        width = w;
        height = h;
        depth = 255;
        data = new Pixel*[h];//address of array is stored in the state variables section
        for (int i = 0; i < h; i++) {
            data[i] = new Pixel[w];//Pixel structure will ultimately be "pixel: with red green blue"
        }
    }
    //destructor
    ~Image() {
        for (int i = 0; i < height; i++) {
            delete [] data[i];
        }
    }
    int getWidth() {
        return width;
    }
    int getHeight() {
        return height;
    }
    void print() {
        //std::cerr << "width " << getWidth() << " height " << getHeight();
        //_write_image("output.ppm", reinterpret_cast<char **>(Image), width, height);
        std::ofstream f("output.ppm");
        f << "P6" << std::endl;
        f << width << " " << height << std::endl;
        f << depth << std::endl;
        for (int i = 0; i < height; i++) {
            f.write(reinterpret_cast<char *>(data[i]), 3*width);
            std::cerr << data[i] << " " << width;
        }
    }
};

int main() {
    Image P6(3,2);
    P6.print();
}