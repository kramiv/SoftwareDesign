//all good. Check the output values. 
//left off on part C after this check. lab day.

//have prof check copy constructor
//and my first method:  IntArray &operator=(IntArray arr)
//if I wanted to do a = b = c, then would I write return *this?
//or how would I do it?
// for = assignment function: return *this;// Return: A reference to this object.
//^^is this correct?
//check  "other assignment operator: []" down below. would it work to have multiple "if"s?
#include<iostream>
class IntArray {
    int size;//number of ints in the array
    int *elt;//star before elt
    static int DEFAULT_SIZE;
public:
//constructor:
    IntArray(int sz) {//positive integer
        size = sz;
        elt = new int[sz];
        for (int i = 0; i < sz; i++) {
            elt[i] = 0;
        }//initialize the values to 0
    }
//default constructor:
    IntArray() {//has default size
    size = DEFAULT_SIZE;
    elt = new int[size];
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        elt[i] = 0;
        }
    }
//copy constructor:
    IntArray(const IntArray &d) {
        size = d.size;
        elt = new int[size];
        for (int i = 0; i < size; i++) {
            elt[i] = d.elt[i];
        }
    }
//destructor:
    ~IntArray() {
        delete [] elt;
    }
//methods
    //the parameter for the assignment operator is usually the same for the copy contsructor. parameter = inside of parantheses
    //note how, below, it is &
    IntArray &operator=(const IntArray &arr) {//return ref to this obj
        size = arr.size;
        delete [] elt;
        elt = new int[arr.size];
        for (int i = 0; i < size; i++) {
            elt[i] = arr.elt[i];
        }
        return *this;//Return: A reference to this object.
    }

    int getSize() {
        return size;
    }
    void display() {
        //display ints in the array
        for (int i = 0; i < size; i++) {
            std::cerr << i << ":  " << elt[i] << '\n';
        }
    }
//other assignment operator: []
//note <= and >= vs < usage for array:
    int &operator[](int i) {
        if (i < size) {//i = 5. 
            if (i >= 0) {
                return elt[i];
            }
        }
        if (i < 0) {
            return elt[0];
            std::cerr << "warning: i out of range of array elt. too small" << '\n';
        }
        if (i >= size) {//if i = size, then it ignores it. same for 0
            return elt[(size - 1)];
            std::cerr << "warning: i out of range of array elt. too big" << '\n';
        }
    }
};

int IntArray::DEFAULT_SIZE = 5;//note: put this outside of main

//comment out and test incrementally:
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

//state variable: elt and size
//class variable: default_size = positive int, default size for elt


//class viarble: first, create the name of the variable under the class
//(public or private he said):
//    static int num_created;  // "class variable"
//then, in main, give it a value:
//  int ConeWeights::num_created = 0;