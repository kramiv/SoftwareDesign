#ifndef _DVD0_H_
#define _DVD0_H_
#include<iostream>

//#include<iostream>
//using namespace std;

class DVD {
    int id;
    char *title;
    char *director;
public://check
//constructor

  DVD(int i, const char *t, const char *dir);
//defult constructor
  DVD();
//copy constructor
  DVD(const DVD &d);
//destructor: 
  ~DVD();
//get methods:
  int getID();
  char *getTitle();
  char *getDirector();
//more methods
  void display();
  void setId(int i);
  void setTitle(const char* t);

  void setDirector(const char* t);
//assignment operator
//returns reference
  DVD &operator=(const DVD &c);
//call in main 
};


#endif