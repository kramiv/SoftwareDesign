//this does not work. methods1 does.
//the first chunk here is fucntion. other copy later
//does not.
#include<iostream>

class Food {//base class
protected:
  bool takeout;
  int order_time;
public:
  Food(bool t) : takeout(t) { 
    order_time = 1;
  }

  void print_takeout() { 
    std::cerr << " takeout " << takeout << std::endl; 
  }
  void delay_order() { order_time += 200; }
  void display() {//fucntion call defined only in base class
    std::cerr << "Food, glorious food!"; 
  }
};


class Ice_Cream : public Food {//derived class
  char kind;  // 'C' chocolate, 'V' vanilla, 'T' twist
public:
  Ice_Cream(bool t, char k) : Food(t), kind(k) { }

  void print_order() { 
    std::cerr << "Ice Cream:  kind " << kind; print_takeout(); 
  }
  void change_flavor(char k2) { kind = k2; }
  void display() {//method only for derived class
    std::cerr << "I scream, you scream...";
  }
  void show_more() {////to create a display fucntion inside of ice_cream that calls food's fucntion:
    std::cerr << "Base class says: ";
    Food::display(); 
  }
};

int main() {
    bool t3 = true;
    Food fd(t3);
    fd.delay_order();//fd is type Food
    Ice_Cream i1(false, 'V');  // not takeout, vanilla flavor
    i1.delay_order();//i1 is a food
    i1.change_flavor('C');
    //fd.change_flavor('C');  // error:  won't compile!
    fd.display();// calls the Food version:  Food, glorious food!
    i1.display();// calls the Ice_Cream version:  I scream...

}


















class Food {//base class
protected:
  bool takeout;
  int order_time;
public:
  Food(bool t) : takeout(t) { 
    order_time = get_current_time(); 
  }

  void print_takeout() { 
    std::cerr << " takeout " << takeout << std::endl; 
  }
  void delay_order() { order_time += 200; }
  void display() {//fucntion call defined only in base class
    std::cerr << "Food, glorious food!"; 
  }
};


class Ice_Cream : public Food {//derived class
  char kind;  // 'C' chocolate, 'V' vanilla, 'T' twist
public:
  Ice_Cream(bool t, char k) : Food(t), kind(k) { }

  void print_order() { 
    std::cerr << "Ice Cream:  kind " << kind; print_takeout(); 
  }
  void change_flavor(char k2) { kind = k2; }
  void display() {//method only for derived class
    std::cerr << "I scream, you scream...";
  }
  void show_more() {////to create a display fucntion inside of ice_cream that calls food's fucntion:
    std::cerr << "Base class says: ";
    Food::display(); 
  }
};

int main() {
    var t3 = true;
    Food fd(t3);
    fd.delay_order();//fd is type Food
    Ice_Cream i1(false, 'V');  // not takeout, vanilla flavor
    i1.delay_order();//i1 is a food
    i1.change_flavor('C');
    fd.change_flavor('C');  // error:  won't compile!
    fd.display();  // calls the Food version:  Food, glorious food!
    i1.display();  // calls the Ice_Cream version:  I scream...

}

/*
Suppose for example that we add a display() method to the base class:

  // in the Food class definition:
  void display() { 
    std::cerr << "Food, glorious food!"; 
  }

and also add a display() method in the derived class:

  // in the Ice_Cream class definition:
  void display() { 
    std::cerr << "I scream, you scream..."; 
  }

Both display() methods have the same name, and they both have the same argument types (zero arguments, in this case), so we say that they have the same signature.  Now, if we call this method on an object of the base class:

  fd.display();  // calls the Food version:  Food, glorious food!

and if we call the method on an object of the derived class:

  i1.display();  // calls the Ice_Cream version:  I scream...




upgrade:
//to create a display fucntion inside of ice_cream that calls food's fucntion:
  // in the Ice_Cream class definition:
  void show_more() {////to create a display fucntion inside of ice_cream that calls food's fucntion:
    std::cerr << "Base class says: "; 
    Food::display(); 
  }

*/

