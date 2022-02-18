#include<iostream>
class IntArray {
    int size;//number of ints in the array
    int *elt;//star before elt
    static int DEFAULT_SIZE;
public:
//constructor:
    IntArray(int sz);
//default constructor:
    IntArray();
//copy constructor:
    IntArray(const IntArray &d);
//destructor:
    ~IntArray() {
        delete [] elt;
    }
//methods
    int getSize() {
        return size;
    }
    void display();
    IntArray &operator=(const IntArray &arr);
    int &operator[](int i);
};

int &IntArray::operator[](int i) {
    if (i < size) {
        if (i >= 0) {
            return elt[i];
        }
    }
    if (i < 0) {
        return elt[0];
            std::cerr << "warning: i out of range of array elt. too small" << '\n';
        }
    if (i >= size) {
        return elt[(size - 1)];
        std::cerr << "warning: i out of range of array elt. too big" << '\n';
    }
}

IntArray &IntArray::operator=(const IntArray &arr) {//return ref to this obj
    size = arr.size;
    delete [] elt;
    elt = new int[arr.size];
    for (int i = 0; i < size; i++) {
        elt[i] = arr.elt[i];
    }
    return *this;
    }


int IntArray::DEFAULT_SIZE = 5;
IntArray::IntArray(int sz) {//constructor
    size = sz;
    elt = new int[sz];
    for (int i = 0; i < sz; i++) {
        elt[i] = 0;
    }
}
IntArray::IntArray() {//default constructor
    size = DEFAULT_SIZE;
    elt = new int[size];
    for (int i = 0; i < DEFAULT_SIZE; i++) {
    elt[i] = 0;
    }
}
IntArray::IntArray(const IntArray &d) {//copy constructor
    size = d.size;
    elt = new int[size];
    for (int i = 0; i < size; i++) {
        elt[i] = d.elt[i];
    }
}
void IntArray::display() {
    for (int i = 0; i < size; i++) {
        std::cerr << i << ":  " << elt[i] << '\n';
    }   
}

int main() {
  IntArray arr1, arr2(3);
  std::cerr << "arr1 has size " << arr1.getSize() << std::endl;
  arr2.display(); std::cerr << std::endl;
 
  arr2[1] = 24;
  arr2.display(); std::cerr << std::endl;
  arr2[389]; // should display an error, but not crash
 
  IntArray arr3(arr2);
  arr3.display();
  arr1 = arr3;
  arr1.display();
  arr2[2] = 63;
  (arr1 = arr2)[0] = -99;
  arr1.display();
}