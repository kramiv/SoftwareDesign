//note "hmm. it worked"

#include<iostream>
using namespace std;

class Animal {
protected:
  char *name;
  float weight;
//hc.name and hc.weight
//whisker_len = hc.whisker_len;
public:
  virtual void init(const char *n, float w) {
    //delete [] name;//this made a segmentation fault
    int len = 0;
    while( n[len] ) { 
      ++len; 
    }
    name = new char[len+1];
    for ( int i = 0; i < len+1; ++i ) {
      name[i] = n[i];
    }
    weight = w;
  }
  void display() {
      std::cerr << "animal message";
  }
  Animal(const char *n, float w) { 
    init(n, w); 
  }

  Animal(const Animal &a) { 
    init(a.name, a.weight); 
  }

  ~Animal() { 
    delete [] name;
    name = 0; 
  }

  float current() const { 
    return weight; 
  }

  float growFast(float s) { 
    weight *= s; 
    return weight; 
  }
};

class HouseCat : public Animal {
  double whisker_len;

public:
  HouseCat(double wl) : Animal("cat", 8) { 
    whisker_len = wl; 
  }

  HouseCat(const HouseCat &hc) : Animal(hc) { 
    whisker_len = hc.whisker_len;
  }
//assignment operator for the Animal class that makes use of the
// init() helper function:
  HouseCat &operator=(const HouseCat &hc) {
    whisker_len = hc.whisker_len;
    delete [] name;//hmm. this worked
    init(hc.name, hc.weight);
    return *this;
  }

  ~HouseCat() {}  // this is really not necessary!

  int getLen() { 
    return whisker_len; 
  }

  void trim() { 
    whisker_len /= 2; 
  }
  void display() {

    std::cerr << '\n' << "whisker len: " << getLen();
  }
};

int main(){
  HouseCat socks(12), waldo(socks);
  waldo = socks;
  waldo.trim();
  waldo.trim();
  waldo.trim();
  std::cerr << waldo.getLen() << std::endl;  // note return type!
//make a pointer for waldo
  Animal *p = &waldo;
  waldo.display();
  std::cerr << '\n';
  p->display();
}
