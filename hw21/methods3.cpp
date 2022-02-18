#include<iostream>
// what is this 4rth line doing? Food &fr = i1;
/* Remember that in this example, fp actually points at an Ice_Cream
 object, and fr refers to the same Ice_Cream object.

The following lines of code are perfectly valid:
  Ice_Cream i1;
  Food *fp;
  fp = &i1;  // legal:  points to a Food!
  Food &fr = i1;  // also legal!
*/

class Food {//base class
protected:
  bool sauce;
  int order_number;
public:
  Food(bool t) : sauce(t) { 
    order_number = 1;
  }
  Food() {
      order_number = 1;
      sauce = 0;
  }

  void print_sauce() { 
    std::cerr << " Will the cheese food have sauce? " << sauce << std::endl; 
  }
  void delay_order() { order_number += 2; }
  void display() {//fucntion call defined only in base class
    std::cerr << "This output is related to the food class " << '\n'; 
  }
  virtual void display2() { //allow printing using references to base class - print 
  //from fucntions of derived class
    std::cerr << "Food, glorious food!"; 
  }

};

class Nachos : public Food {
    bool cheese;
public:
    Nachos(bool t) : Food(t), cheese(t) { }
    void display2() {
        std::cerr << " This is Nachos's output " << '\n';
    }
};

class Quesadilla : public Food {
    bool cheese;
    bool salsa;
    bool quac;
public:
    Quesadilla(bool t, bool k, bool r) : Food(t), cheese(t), salsa(k), quac(r) { }
    void display() {
        std::cerr << " This is Quesadilla's output " << '\n';
    }
};

class Sweaty_Cheese : public Food {//derived class
  char kind;  // 'R' regular sweaty, 'E' extra sweaty
public:
  Sweaty_Cheese(bool t, char k) : Food(t), kind(k) { }
  
  Sweaty_Cheese() {
      bool t = 0;
      char k = 'R';
      kind = k;
  }
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
  void display2() { 
    std::cerr << "I scream, you scream..."; //allow printing using references to base class - print 
  //from fucntions of derived class
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
    Sweaty_Cheese i2;//Create an object of the derived class type.
    Food *fp1;//Create a pointer and a reference of the base class type.
    fp1 = &i2;//Create a pointer and a reference of the base class type.
    //call methods on teh pointer and the reference:
    Food &fr = i2;//what does this do?
    fr.print_sauce();
    fp1->print_sauce();
    //i2.change_flavor('E');//will not compile
    fr.display2();  // reference, output:  I scream, you scream...
    fp1->display2();  // pointer, output:  I scream, you scream...
//Now, if we try to call display2() using a reference or pointer of 
//base class type, but which actually refers to a subclass, then 
//we will actually call the function in the subclass:
    Nachos n1(true);
    Food *fp2;
    fp2 = &n1;
    Food &fr2 = n1;
    fr2.display2();//output: Nachos output
    fp2->display2();//output: Nachos output
/*
Notice that, with a virtual function, when we seem to be calling the 
hod of the base class, we actually end up calling the method of the 
appropriate derived class.  If we don't have a method in the derived
 class, as for example, we don't have a display2() method in a 
 Quesadilla, then we stick with the method in the base class:
*///note how Nachos calls display2 from Food, so it prints nacho's 
//output using references where quesadilla calls display, which will 
//print out Food's output using references
    Quesadilla q1(true, false, false);  // takeout, whole, ultimate
    Food *fp3;
    fp3 = &q1;
    Food &fr3 = q1;
    fr3.display2();  // output:  Food, glorious food!
    fp3->display2();  // output:  Food, glorious food!


}


    /*
    Ice_Cream i2;
    Food *fp;
    fp = &i2;  // legal:  points to a Food!
    Food &fr = i2;  // also legal!
    fr.print_takeout();  // a reference can call the function
    //output:  takeout false
    fp->print_takeout();  // a pointer needs to dereference/use ->
    //output:  takeout false
    fr.display();  // output:  Food, glorious food! (from Food class)(can't use Ice_Cream class's display)
    fp->display();  // output:  Food, glorious food! (can't use Ice_Cream class's display)
    //fr.change_flavor('T');  // error, won't compile
    */



/*
The following lines of code are perfectly valid:

  Ice_Cream i1;
  Food *fp;
  fp = &i1;  // legal:  points to a Food!
  Food &fr = i1;  // also legal!

*/