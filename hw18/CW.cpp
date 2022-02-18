#include<iostream>

class ConeWeights {
  int num_cones;
  float *data;
public:
  // constructors
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
  ConeWeights c1(3), c2(4);
  c1.assign_cone_weight(0, 125.5);
  c2 = c1;
  c2.display();
}
