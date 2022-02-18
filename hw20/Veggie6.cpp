#include<iostream>


class Veggie {
  char *name;
  int calories;
public:
  Veggie (const Veggie &z) {
    int len = 0;
    while (z.name[len++]) { } 
    name = new char[len]; 
    for (int i = 0; i < len; ++i) {
      name[i] = z.name[i]; 
    }
    calories = z.calories;
  }

  Veggie() {
      name = 0;
      calories = 1;
  }
  
  Veggie(int c) : calories(c){
    //calories = c; 
    name = 0; 
  }

  Veggie(const char *n, int c) {
    calories = c; 
    int len = 0; 
    while (n[len++]) { } 
    name = new char[len]; 
    for (int i = 0; i < len; ++i) {
      name[i] = n[i]; 
    } 
  }

  void print() { 
    if (name) {
      std::cerr << name << " calories " << calories << std::endl;
    } else {
      std::cerr << calories << std::endl;
    }
  }
  Veggie &operator=(const Veggie &a) {
      int c = 0;
      while (a.name[c] != '\0') {
          c++;
      }
      for (int i = 0; i < c; i++) {
          name[i] = a.name[i];
      }
      calories = a.calories;
      return *this;
  }


  ~Veggie() { 
    if (name) {
      std::cerr << "deallocating " << name << std::endl;
    }
    delete [] name;  // does not do anything if name is zero
  }
};
//subclass Store with float price and float storage_temperature
class Store : public Veggie {
    float price;
    float storage_temperature;
public:
    Store(float p, float s_t) : price(p), storage_temperature(s_t) {
    }
};
class Animation : public Veggie {
    int scale;
    int orientation;
public:
    Animation(int s, int o) : scale(s), orientation(o) {
    }
};
//subclass Animation with int scale and int orientation

int main() { 
  Veggie a("kale", 42);
  Veggie b("brocc", 33);
  //Veggie c(10);
  //Veggie* d[4];
  //Veggie w();
  //Veggie e(a);//copy constructor
  Veggie e = a;//assignment operator
  Store d();
  //d[0] = &a; 
  //d[1] = &b; 
  //d[2] = &c; 
  //Veggie **e = d; 
  //e[2]->print();  // first line of output;  where are the others?
}