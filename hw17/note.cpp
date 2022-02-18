#include<iostream>
//ratings.cpp from hw 15 or 16 also uses stream as argument
class Note {
  char *sender;
  char *message;

public:
  Note() {  // this constructor is called a default constructor
    sender = new char[3];
    sender[0] = 'A';  
    sender[1] = 'B';  
    sender[2] = 0;
    
    message = new char[3];
    message[0] = 'h';  
    message[1] = 'i';  
    message[2] = 0;
  }
  Note(const Note &c) {
      sender = new char[3];
      message = new char[3];
      for (int i = 0; i < 3; i++) {
          sender[i] = c.sender[i];
          message[i] = c.message[i];
      }
  }

  ~Note() { 
    delete [] sender; delete [] message; 
  }

  void display(std::ostream &os) {
    os << "sender: " << sender << " ";
    os << "message: " << message << "\n";
  }
};
void f(Note b) {
    b.display(std::cerr);//shouldn't this output AB message: hi    ?
}
int main() {
  Note n1, n2;
  n1.display(std::cerr);  // output  sender: AB message: hi
  f(n1);
  //Note n1copy(n1);   add this to make sure I am calling the copy contsructor
}
