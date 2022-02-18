//good
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
    Pixel** data;//points to array of pointers: create variable for address before
    //deleting array in squeeze?
public:
    //constructors - unedited
    Image(int w, int h) {//dynamically allocate Pixels for width, height
        width = w;
        height = h;
        depth = 255;//"new --" gives a memory address
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
            //std::cerr << data[i][1].green << "      ";

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
    void zeroRed() {//red = first one. access pointer of pointer
        for (int i = 0; i < height; i++) {
            for (int k = 0; k < width; k++) {//do it for 1 row
                data[i][k].red = 0;
                //data[i][k].green = 0;
                //data[i][k].blue = 255;
            }
        }
    }
    void grayScale() {
        for (int i = 0; i < height; i++) {
            for (int k = 0; k < width; k++) {//do it for 1 row
                char a = data[i][k].red;
                char b = data[i][k].green;
                char c = data[i][k].blue;
                char ave = (a + b + c)/3;
                data[i][k].red = ave;
                data[i][k].green = ave;
                data[i][k].blue = ave;
            }
            }
        }
    void horizSqueeze() {
        int h = (height);//only change the width
        int w = (width/2);
        //create my temporary array: 1/2 size
        Pixel** temp;//data[0] and data[1]                      data[0][0] and data[0][1]
        //heap [..., @1000 16 (data's 2 rows of arrays = 8*2), @1016 (3 bytes per pixel = 9 bytes) 9, @1025 9, ...]
        temp = new Pixel*[h];//address of array is stored in the state variables section
        //line 85 add to heap [...]
        //line 89 add to heap [...]
        for (int i = 0; i < h; i++) {//h=2
            temp[i] = new Pixel[w];//w=1
        }//Then, assign them equal
        //for every other value of the loop below.
        //h=height=2, width=3, w=1.
        for (int i = 0; i < h; i++) {//h=2(=height. not squeezed)
            for (int k = 0; k < w; k++) {//w=1
                temp[i][k].green = data[i][2*k].green;
                temp[i][k].blue = data[i][2*k].blue;
                temp[i][k].red = data[i][2*k].red;
                }
            }
        //delete array data
        //error here
        
        for (int i = 0; i < height; i++) {
                delete [] data[i];//delete data's heap information: release @1016, then @1025
            }
        delete [] data;//data at this memory address + memory address isn't needed anymore
        ///heap [...temp's info. ] release @1000
        //then, create data** again at 1/2 size
        
        //Pixel** data;//I don't need to recreate data
        //line 112: add data information to heap again heap [...temp + data...]
        data = new Pixel*[h];//address of array is stored in the state variables section
        for (int i = 0; i < h; i++) {
            data[i] = new Pixel[w];
        }//set equal to old loop
        
        for (int i = 0; i < h; i++) {
            for (int k = 0; k < w; k++) {//do it for 1 row
                data[i][k].red = temp[i][k].red;
                data[i][k].green = temp[i][k].green;
                data[i][k].blue = temp[i][k].blue;
            }
        }//delete temp
        for (int k = 0; k < h; k++) {//go along scanline
                delete [] temp[k];//delete this scanline
            }//delete heap info for temp from heap [...data]   :end of main: delete heap's data info.
        delete [] temp;
        width = w;//update the new width of myimg
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
    //myimg.zeroRed();
    //myimg.grayScale();
    myimg.horizSqueeze();//I release data that was created under Image myimg
    //then, I reach the end of main(), there is nothing to delete. = error
    myimg.print();
}