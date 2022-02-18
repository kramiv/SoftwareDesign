//line 32: "image" part - not sure if correct.
// go over this + fix errors. directions unclear.
#include<iostream>
#include<fstream>
//add pixel struct.
struct Pixel {//gaurantees that whenever I make Pixel, it will be 3 bytes.
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
        }//line above: building an array of pixels
    }
    Image(const char* a) {//this will read information into the code
        std::ifstream f(a);//inputting into the .cpp, not into file.
        char name[3];
        f >> name;
        f >> width;
        f >> height;
        f >> depth;
        data = new Pixel*[height];
        for (int i = 0; i < height; i++) {
            data[i] = new Pixel[width];
        }//create spots for i scanlines with int-width Pixels (each have 3 bytes)
        f.get();//read in newline character before pixel info
        for (int i = 0; i < height; i++) {//below: # of bytes and where it's putting it.
            f.read(reinterpret_cast<char *>(data[i]), width*3);//read scanline at a time, # of bytes
        }
    }
    //destructor
    ~Image() {
        for (int i = 0; i < height; i++) {
            delete [] data[i];//deallocating the memory addresses of the scanlines
            //that were created so far
        }
        delete [] data;//delete the array that held the memory addresses of scanlines
    }
    //methods:
        //reinterpret (cast) the pointer to be a char * also


        //sets up state variables for fname
        



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
        f << "P6" << "\n";
        f << width << " " << height << "\n";
        f << depth << "\n";
        for (int i = 0; i < height; i++) {
            f.write(reinterpret_cast<char *>(data[i]), width*3);
        }
//include PPM header information and content of my arrays?
    }
};

int main() {
    Image myimg("tiny.ppm");
    myimg.print();
}