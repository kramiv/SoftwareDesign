#include<iostream>
//using namespace std;
class Point {
  float x, y, z;

public:
  Point(float a, float b, float c): x(a), y(b), z(c) {}

  void display() const { 
    std::cerr << x << ' ' << y << ' ' << z << '\n'; 
  }
  float &operator[](int index) {//use brackets to return x, y, or z depending on int index
    if (0 == index) return x;
    else if (1 == index) return y;
    else if (2 == index) return z;
    std::cerr << "Error, bad index." << std::endl;
    return x;
  }//this worked when I removed all spaces in function name and added &

};

//We've made our display() method a const, since it won't 
//change anything about the object that it is called on

int main() {
    Point p(1, 2, 3);
    p.display();   // outputs 1 2 3

    //test operator function []:
    std::cerr << p[1] << std::endl;//outputs 2
    p[1] = 5;
    p.display(); // should output 1 5 3
};



/*
If we were defining the operator outside the class, we might do 
so like this:
    float operator[] (const Point &q, int index) { ...
but since the first argument is a member of our class, it 
will probably be more convenient to define a member function 
that starts like this in the Point class definition:
    float operator[] (int index) {
    if (0 == index) return x;
    else if (1 == index) return y;
    else if (2 == index) return z;
    std::cerr << "Error, bad index." << std::endl;
    return x;
  }
*/