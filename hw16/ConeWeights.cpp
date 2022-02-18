#include<iostream>

class ConeWeights {
  int num_cones;
  float *data;
public:
// constructor
  ConeWeights(int n) { 
    num_cones = n; 
    data = new float[num_cones];
  }
  void multiply (int i, float w) {
      data[i] = w*2;
  }
  void increase_size (int &i) {
      //add one new member to the array, and make
      //the last one 0.
    float *temp;
    temp = new float[i + 1];
    for (int k = 0; k < i; k++) {
        temp[k] = data[k];
    }
    temp[i + 1] = 0;
    for (int k = 0; k < (i + 1); k++) {
        data[k] = temp[k];
    }
    num_cones = (i + 1);
  }


  // destructor
  ~ConeWeights() { 
    std::cerr << "bye!" << std::endl; 
    delete [] data; 
  }

  void assign_cone_weight(int i, float &w) { 
    data[i] = w; 
  }
  
  void display() { 
    std::cerr << "num_cones " << num_cones << std::endl;
  }
};

int main() {
  int i = 3;
  ConeWeights cs(i); // constructor is automatically called here
  float w = 125.5;
  cs.assign_cone_weight(0, w);
  cs.multiply(0, w);
  cs.increase_size(i);
  ///add here, use data[i] = w*2;
  cs.display();
  // invisible feature:  the destructor is automatically called here!
}
