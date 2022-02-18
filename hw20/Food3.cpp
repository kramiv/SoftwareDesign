
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
  Food(bool t, long k) : takeout(t), order_time(k) {
    }

  void print_takeout() { 
    std::cerr << " takeout " << takeout << std::endl; 
  }
};

class Nachos : public Food {
public:
  Nachos(bool t) : Food(t) { }

  void print_order() { 
    std::cerr << "Nachos: "; 
    print_takeout(); 
  }
};

class Quesadilla : public Food {
  bool is_half, just_cheese;

public:
  Quesadilla(bool h, bool c) : Food(h, c), is_half(h), just_cheese(c) { }

  void print_order() { 
    std::cerr << "Quesadilla:  is_half " << is_half;
    std::cerr << " just_cheese " << just_cheese; 
    print_takeout(); 
  }
};
class Chicken_Quesadilla : public Quesadilla {
    bool chicken;
    bool cheese;
public:
    Chicken_Quesadilla(bool h, bool c) : Quesadilla(h, c), chicken(h), cheese(c) { }
    void print_order() {
        std::cerr << "Chicken Quesadilla chicken " << chicken << " cheese " << cheese;
        print_takeout();
    }
};

class Hot_Dog : public Food {
    char topping;//'R' relish, 'K' ketchup, 'M' mustard
public:
    Hot_Dog(bool t, char k) : Food(t), topping(k) { }
    void print_order() {
        std::cerr << "Hot Dog topping " << topping;
        print_takeout();
    }
};

class Ice_Cream : public Food {
  char kind;  // 'C' chocolate, 'V' vanilla, 'T' twist

public:
  Ice_Cream(bool t, char k) : Food(t), kind(k) { }

  void print_order() { 
    std::cerr << "Ice Cream:  kind " << kind; 
    print_takeout(); 
  }
};

int main() {
  Nachos n1(false);
  Ice_Cream i1(true, 'V'), i2(false, 'T');
  i2.print_order();
  Hot_Dog d1(true, 'R');
  d1.print_order();
  Quesadilla q1(true, true);
  q1.print_order();
  Chicken_Quesadilla cq1(true, true);
  cq1.print_order();
}