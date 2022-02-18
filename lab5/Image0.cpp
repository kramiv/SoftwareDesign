//create a class
#include<iostream>
class Image0 {
    int width;
    int height;
public:
    //constructors
    Image0(int w, int h) {
        width = w;
        height = h;
    }
    int getWidth() {
        return width;
    }
    int getHeight() {
        return height;
    }
    void display() {
        std::cerr << "width " << getWidth() << " height " << getHeight();
    }
};

int main() {
    Image0 i1(1,3);
    i1.display();
}