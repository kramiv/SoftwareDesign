//new error seems to have appeared: Nachos is "pure" and 
//so I can't create Nachos n1(false);.
//I can't get const to work either.
#include<iostream>
#include<chrono>  // used for get_current_time()
#include<sys/stat.h> // used for get_current_time()
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
  long long order_time;

public:
  Food(bool t) : takeout(t) { 
    order_time = get_current_time(); 
  }

  void print_takeout() const { 
    std::cerr << " takeout " << takeout << '\n'; 
  }

  void delay_order() { 
    order_time += 500; 
  }

  virtual void display() const { 
    std::cerr << "Food, glorious food!\n"; 
  }
  virtual void print_order() = 0;
};

class Nachos : public Food {
public:
  Nachos(bool t) : Food(t) { }
//in Nachos class:
  //void print_order() { 
  //  std::cerr << "Nachos: " << '\n'; 
  //  print_takeout(); 
  //}
};

class Quesadilla : public Food {
  bool is_half, just_cheese;

public:
  Quesadilla(bool t, bool h, bool c) : Food(t), is_half(h), just_cheese(c) { }

  void print_order () const { 
    std::cerr << "Quesadilla:  is_half " << is_half << '\n';
    std::cerr << " just_cheese " << just_cheese << '\n'; 
    print_takeout(); 
  }
};

class Ice_Cream : public Food {
  char kind;  // 'C' chocolate, 'V' vanilla, 'T' twist

public:
  Ice_Cream(bool t, char k) : Food(t), kind(k) { }

  void print_order() const { 
    std::cerr << "Ice Cream:  kind " << kind << '\n' ; 
    print_takeout(); 
  }

  void change_flavor(char k2) { 
    kind = k2; 
  }

  void display() { 
    std::cerr << "I scream, you scream...\n"; 
  }

  void show_more() const { 
    std::cerr << "Base class says: \n"; 
    Food::display(); 
  }
};
int main() {
  Nachos n1(false);
  Ice_Cream i1(false, 'V'), i2(false, 'T');
  
  Food *orders[3];
  orders[0] = &n1;
  orders[1] = &i1;
  orders[2] = &i2;

  for (int i = 0; i < 3; ++i) {
    orders[i]->display();
  }
  for (int i = 0; i < 3; ++i) {
    orders[i]->print_order();
  }
  //Food p2(true);
  //p2.print_order();
//In main(), create an example of a const Ice_Cream
// object and verify that you can still call a 
//variety of (const) methods on that object.
  //Ice_Cream i2(false, 'T');
  //i2.display();
  //i2.show_more();


}
