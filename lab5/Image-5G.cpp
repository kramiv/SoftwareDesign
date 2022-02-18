//tell Linh to check for missing programs here (final program)
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
    Image(const Image &d) {
        width = d.width;
        height = d.height;
        depth = 255;
        data = new Pixel*[height];//address of array is stored in the state variables section
        for (int i = 0; i < height; i++) {
            data[i] = new Pixel[width];
        }
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                data[j][k] = d.data[j][k];
            }
        }
        print();
    //create array and set values equal?
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
    void addBorder() {
        //create temporary array
        int w = width + 6;
        int h = height + 6;
        Pixel** temp;
        temp = new Pixel*[h];
        for (int i = 0; i < h; i++) {
            temp[i] = new Pixel[w];
        }
        //set original array equal to temp array from i 6 to width - 6
        for (int i = 3; i < 4; i++) {
            for (int k = 3; k < 5; k++) {
                temp[i][k].red = data[i - 3][k - 3].red;//01 height and 
                temp[i][k].green = data[i - 3][k - 3].green;//012 width
                temp[i][k].blue = data[i - 3][k - 3].blue;
        }
        }//delete original array
        
        for (int i = 0; i < height; i++) {
            delete [] data[i];
        }
        delete [] data;
        //create new data array
        
        //Pixel** data;
        data = new Pixel*[h];
        for (int i = 0; i < h; i++) {
            data[i] = new Pixel[w];
        }//set new data array equal to temp
        for (int i = 3; i < (h - 3); i++) {
            for (int k = 3; k < (w - 3); k++) {
                temp[i][k].red = data[i][k].red;
                temp[i][k].green = data[i][k].green;
                temp[i][k].blue = data[i][k].blue;
        }//add color for borders (or are they filled randomly?)
        }
        //if I want to change the border colors, I do it
        //like this. Otherwise, it's filled with junk.
        data[0][0].red = 255;
        data[0][1].red = 255;
        data[0][3].red = 255;
        data[1][0].red = 255;
        data[1][1].red = 255;
        data[1][2].red = 255;
        
       width = w;
       height = h;
        
    }
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
    myimg.addBorder();
    myimg.print();
    //Image myimg2(myimg);//this and the one below work to call copy constructor
    Image myimg2 = myimg;
    myimg2.print();
}









//copy constructor
//call a function that takes up image as parameter, not reference
//takes up the image in the methods or in the function call?
//because, if I take up the actual Image by name, how is it different from
//the actual contsructor then?