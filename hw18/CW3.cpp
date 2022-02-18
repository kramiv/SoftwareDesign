int ConeWeights::num_created = 0;

#include <iostream>
class ConeWeights {
  int num_cones;
  float *data;
public:
  // constructors
  //static int num_created;//number of ConeWeights created
  ++num_created;
  ConeWeights(int n) { 
    num_cones = n; 
    data = new float[num_cones]; 
  }

  ConeWeights(const ConeWeights &c) {
    num_cones = c.num_cones;
    data = new float[num_cones];
    for (int i = 0; i < num_cones; ++i) { 
      data[i] = c.data[i];
    }
  }
  //why is it &operator 
  //this returns the value so it can be used
  ConeWeights &operator=(const ConeWeights &c) { // version 4
    num_cones = c.num_cones;
    delete [] data;
    data = new float[c.num_cones];
    for (int i = 0; i < c.num_cones; ++i) {
      data[i] = c.data[i];
    }
    return *this;//return left hand side: c2 = c1;
    //sets the memory addresses equal?
  }



  // destructor
  ~ConeWeights() { 
    std::cerr << "bye!" << std::endl; 
    delete [] data; 
  }

  void assign_cone_weight(int i, float w) { 
    data[i] = w; 
  }

  void display() { 
    std::cerr << "num_cones " << num_cones << std::endl;
  }
};


int main() {
  ConeWeights c1(3), c2(4), c3(0);
  c1.display();
  c2.display();
  c3.display();
  std::cerr << "reassign ";
  c1.assign_cone_weight(0, 125.5);
  c2 = c1 = c3;
  c1.display();
  c2.display();
  c3.display();
}