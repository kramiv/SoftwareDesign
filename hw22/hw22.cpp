//note line 90 or 91 with virtual function
//by default, pointer will use the subclass's 
//function. Otherwise, it will use virtual function
//in superclass.
//or, if called like Class::function();, it will
//use the superclass function
#include<iostream>
#include<chrono>  // used for get_current_time()
#include<sys/stat.h>  // used for get_current_time()

long fake_time = 1;

long get_current_time() { 
  long ms; 
  if (0) {  // actual time
    using namespace std::chrono;
    ms = duration_cast< milliseconds >(
      system_clock::now().time_since_epoch()).count();
  } else {
    ms = fake_time++; 
  }
  return ms;
}

class Food {
protected:
  bool takeout;
  long order_time;

public:
  Food(bool t) : takeout(t) { 
    order_time = get_current_time();  
  }

  void print_takeout() {  
    std::cerr << " takeout " << takeout << std::endl; 
  }

  void delay_order() { 
    order_time += 500;  
  }

  virtual void display() { 
    cout << "Food, glorious food!\n"; 
  }
};

class Nachos : public Food {
public:
  Nachos(bool t) : Food(t) {
  }

  void print_order() { 
    std::cerr << "Nachos: "; 
    print_takeout(); 
  }
};

class Quesadilla : public Food {
  bool is_half, just_cheese;

public:
  Quesadilla(bool t, bool h, bool c) : Food(t), is_half(h), just_cheese(c) {
  }

  void print_order() { 
    std::cerr << "Quesadilla:  is_half " << is_half;
    std::cerr << " just_cheese " << just_cheese; 
    print_takeout(); 
  }
};


class Ice_Cream : public Food {
  char kind;  // 'C' chocolate, 'V' vanilla, 'T' twist

public:
  Ice_Cream(bool t, char k) : Food(t), kind(k) {
  }

  void print_order() { 
    std::cerr << "Ice Cream:  kind " << kind; 
    print_takeout(); 
  }

  void change_flavor(char k2) {  
    kind = k2; 
  }

  void display() { 
    cout << "I scream, you scream...\n"; 
  }

  void show_more() { 
    cout << "Base class says: "; 
    Food::display(); ////////NOTE THIS
  }
};


int main() {
  Nachos n1(false);
  Ice_Cream i1(true, 'V'), i2(false, 'T');

  Food *orders[3]; 
  orders[0] = &n1; 
  orders[1] = &i1; 
  orders[2] = &i2; 

  for (int i = 0; i < 3; ++i) {
    orders[i]->display();
  } 
}