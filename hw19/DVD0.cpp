#include<iostream>
using namespace std;

class DVD {
    int id;
    char *title;
    char *director;
public://check
//constructor
  DVD(int i, const char *t, const char *dir) {//check
    id = i;
    title = new char[30];//get_len
    for (int i = 0; i < 30; i++) {
        title[i] = t[i];
    }
    director = new char[30];//get_len
    for (int j = 0; j < 30; j++) {
        director[j] = dir[j];
    }
  }
//defult constructor
  DVD() {
    id = 0;
    title = new char[75];//check. +get_len?
    director = new char[75];//check
    for (int i = 0; i < 75; i++) {//check
        title[i] = '\0';
        director[i] = '\0';
    }
  }
//copy constructor
  DVD(const DVD &d) {//copy constructor: same name as constructor
    id = d.id;
    //create new array + allocate from)
    int a = 0;//check _get_len
    int b = 0;
    while (d.title[a] != '\0') {
      a++;
    }
    while (d.director[b] != '\0') {
      b++;
    }
    //if ( title ) delete [] title;//this messed up my copy constructor
    //if ( director ) delete [] director;//and this messed it up
    title = new char[a + 1];
    director = new char[b + 1];
    for (int i = 0; i < a; i++) {
        title[i] = d.title[i];//check
    }
    for (int j = 0; j < b; j++) {
        director[j] = d.director[j];
    }
    title[a] = '\0';
    director[b] = '\0';

  }
//destructor: 
  ~DVD() {
    delete [] title;//if ( title ) 
    delete [] director;
  }
//get methods:
  int getID() {
    return id;
  }
  char *getTitle() {
    return title;
  }
  char *getDirector() {
      return director;
  }
//more methods
  void display() {
      std::cerr << "[" << id << ".   " << title << "/" << director << "]";
  }
  void setId(int i) {
      id = i;
  }
  void setTitle(const char* t){//Fix while loops
    delete [] title;
//t is 'input', title is "member data".  (not class variable - shared by all objects.)
    int a = 0;
    while (t[a] != '\0') {
      a++;
    }
    title = new char[a + 1];
    for (int i = 0; i < a; i++) {
        title[i] = t[i];
    }
    title[a] = '\0';
  }//note: check loops with numbers like in physics.

  void setDirector(const char* t) {
    delete [] director;
    int b = 0;
    while (t[b] != '\0') {
      b++;
    }
    director = new char[b + 1];
    for (int i = 0; i < b; i++) {
        director[i] = t[i];
    }
    director[b] = '\0';
  }
//assignment operator
//returns reference
  DVD &operator=(const DVD &c) {
   //delete [] title;
   //delete [] director; This is also not necessary as with copy contsructor
   //deleting soemthing that's not there
   //confuses it.
   //if ( title ) delete [] title; also doesn't work.
   int a = 0;
   int b = 0;
   while (c.title[a] != '\0') {
     a++;
     }
   while (c.director[b] != '\0') {
      b++;
     }
   for (int i = 0; i < a; i++) {
       title[i] = c.title[i];
   }
   for (int j = 0; j < b; j++) {
       director[j] = c.director[j];
   }
   id = c.id;
   return *this;//check (p10)//returns object
  }
//call in main 
};

int main() {
  char str[] = "Gandhi";
  DVD d1(4, str, "Richard Attenborough");
  DVD d2;//empty
  DVD d3(d1);//they are equivalent - see if this works   ---copy contsructor
  //in a smaller function or if I need an operator.
  cout << "After constructors:" << endl;
  d1.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
  d2.display(); cout << endl; // [0.  /]
  d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
 
  str[0] = 'X';

  cout << "Test for dynamically allocated copies" << endl;
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

  d3 = d2;//fix this
  d2.setTitle("Wild Strawberries");
  
  cout << "After more state changes:" << endl;
  d1.display(); cout << endl; // [2.  Shadowlands/Richard Attenborough]
  d2.display(); cout << endl; // [0.  Wild Strawberries/Ingmar Bergman]
  d3.display(); cout << endl; // [0.  /Ingmar Bergman]

}


//methods: getID();, getTitle(), getDirector()
