#include<iostream>

class Food {//base class
protected:
  bool sauce;
  int order_number;
public:
  Food(bool t) : sauce(t) { 
    order_number = 1;
  }

  void print_sauce() { 
    std::cerr << " Will the cheese food have sauce? " << sauce << std::endl; 
  }
  void delay_order() { order_number += 2; }
  void display() {//fucntion call defined only in base class
    std::cerr << "This output is related to the food class " << '\n'; 
  }
};


class Sweaty_Cheese : public Food {//derived class
  char kind;  // 'R' regular sweaty, 'E' extra sweaty
public:
  Sweaty_Cheese(bool t, char k) : Food(t), kind(k) { }

  void print_order() { 
    std::cerr << "Type of sweaty dog cheese:  " << kind; print_sauce(); 
  }
  void change_flavor(char k2) { kind = k2; }
  void display() {//method only for derived class
    std::cerr << "I scream, you scream, we all scream for sweaty dog cheese..." << '\n';
  }
  void show_more() {////to create a display fucntion inside of Sweaty_Cheese that calls food's fucntion:
    std::cerr << "This is a display() call to the base class which says: ";
    Food::display(); 
  }
};

int main() {
    bool t3 = true;
    Food fd(t3);
    fd.delay_order();//fd is type Food
    Sweaty_Cheese i1(false, 'R');  // not sauce, vanilla flavor
    i1.delay_order();//i1 is a food
    i1.change_flavor('E');
    //fd.change_flavor('C');  // error:  won't compile!
    fd.display();// calls the Food version:  Food, glorious food!
    i1.display();// calls the Sweaty_Cheese version:  I scream...
    i1.show_more();//calls food display from subclass display
    Ice_Cream i2;
    Food *fp;
    fp = &i2;  // legal:  points to a Food!
    Food &fr = i2;  // also legal!
    fr.print_takeout();  // a reference can call the function
    //output:  takeout false
    fp->print_takeout();  // a pointer needs to dereference/use ->
    //output:  takeout false
    fr.display();  // output:  Food, glorious food! (from Food class)
    fp->display();  // output:  Food, glorious food! (can't use Ice_Cream class's display)
    //fr.change_flavor('T');  // error, won't compile
}