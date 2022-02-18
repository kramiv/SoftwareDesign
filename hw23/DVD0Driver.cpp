#include "DVD0.h"
//#include "DVD0.cpp"
#include <iostream>S
using namespace std;

int main() {
  char str[] = "Gandhi";
  DVD d1(4, str, "Richard Attenborough");
  DVD d2;//empty
  DVD d3(d1);//they are equivalent - see if this works   ---copy contsructor
  //in a smaller function or if I need an operator.
  std::cerr << "After constructors:";
  d1.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
  d2.display(); cout << endl; // [0.  /]
  d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
 
  str[0] = 'X';

  std::cerr << "Test for dynamically allocated copies";
  d1.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
  d2.display(); cout << endl; // [0.  /]
  d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
 
  cout << d2.getID() << endl; // 0
  cout << d1.getTitle() << endl; // Gandhi
  cout << d1.getDirector() << endl; // Richard Attenborough
 
  d1.setId(2);
  d1.setTitle("Shadowlands");
  d2.setDirector("Ingmar Bergman");

  cout << "After state changes:" << endl;
  d1.display(); cout << endl; // [2.  Shadowlands/Richard Attenborough]
  d2.display(); cout << endl; // [0.  /Ingmar Bergman]
  d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]

  d3 = d1;//fix this
  d2.setTitle("Wild Strawberries");
  
  cout << "After more state changes:" << endl;
  d1.display(); cout << endl; // [2.  Shadowlands/Richard Attenborough]
  d2.display(); cout << endl; // [0.  Wild Strawberries/Ingmar Bergman]
  d3.display(); cout << endl; // [0.  /Ingmar Bergman]

}