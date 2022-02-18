#include "DVD0.h"
using namespace std;

DVD::DVD(int i, const char *t, const char *dir) {
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
DVD::DVD() {
    id = 0;
    title = new char[30];//check. +get_len?
    director = new char[30];//check
    for (int i = 0; i < 30; i++) {//check
        title[i] = '\0';
        director[i] = '\0';
    }
  }

DVD::DVD(const DVD &d) {//copy constructor: same name as constructor
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

DVD::~DVD() {
    delete [] title;//if ( title ) 
    delete [] director;
  }
  
void DVD::setTitle(const char* t){
    delete [] title;
    int a = 0;
    while (t[a] != '\0') {
      a++;
    }
    title = new char[a + 1];
    for (int i = 0; i < a; i++) {
        title[i] = t[i];
    }
    title[a] = '\0';
  }

int DVD::getID() {
    return id;
  }

char *DVD::getTitle() {
    return title;
  }
char *DVD::getDirector() {
      return director;
  }
void DVD::display() {
      std::cerr << "[" << id << ".   " << title << "/" << director << "]" << "\n";
  }
void DVD::setId(int i) {
  id = i;
}
DVD &DVD::operator=(const DVD &c) {
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

  void DVD::setDirector(const char* t) {
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