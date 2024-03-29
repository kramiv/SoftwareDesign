#include<iostream>
using namespace std;

class ConeWeights {
  int num_cones;
  float *data;

public:
  // constructor
  ConeWeights(int n) { 
    num_cones = n; 
    data = new float[num_cones]; 
  }
  //copy constructor
  ConeWeights(const ConeWeights &b) {
    num_cones = b.num_cones;
    data = new float[b.num_cones];
    for (int i = 0; i < b.num_cones; ++i) {
      data[i] = b.data[i];
    }
  }

  // destructor
  ~ConeWeights() { 
    cout << "bye!" << endl; delete [] data; 
  }

  void assign_cone_weight(int i, float w) { 
    data[i] = w; 
  }

  void display() { 
    cout << "num_cones " << num_cones << endl;
  }
};
void f(ConeWeights d) {
  d.display();
}

int main() {
  ConeWeights c1(3);
  c1.assign_cone_weight(0, 125.5);
  f(c1);
}