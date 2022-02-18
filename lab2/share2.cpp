#include<iostream>//use cout and cin
#include <fstream>//read file stream?
//#include "../show_mem.h"
const int mem_size = 10000;
char _global_mem[mem_size];//it is 10,000 chars (abcd...)
///////////////////////////////////////
void read_stream(std::istream &f, char array[], int max_size) {
  int num_bytes;
  if (f.good()) {
    f.read(array, max_size);
    if (f) {
      std::cerr << "Warning in read_stream:  did not reach end of stream after " << max_size << " characters.";
      num_bytes = max_size - 1;
    } else {
      num_bytes = f.gcount();
      if (num_bytes >= max_size) num_bytes = max_size - 1;
    }
  } else {
    std::cerr << "Warning in read_stream: unable to read anything\n";
    num_bytes = 0;
  }
  array[num_bytes] = 0;  // assign null at end
}
///////////////////////////////////////
void read_file(char fname[], char array[], int max_size) {
  std::ifstream f(fname);
  read_stream(f, array, max_size);
  std::cerr << fname << std::endl;
  f.close();
}
///////////////////////////////////////
void server(char fname[], bool first_time) {//void if no return
    first_time = true;
    while(1) {
        if (first_time) {
            std::cout << "What file would you like? ";
        } else {
            read_file(fname, _global_mem, mem_size);
        }
        first_time = false;///new code
        std::cin.getline(fname, 20);//reads the user's input
    }
}
///////////////////////////////////////

void client(char fname[], bool first_time) {
    first_time = false;
    while(1) {
        if (first_time) {
            std::cout << _global_mem;
            std::cin.getline(fname, 20);
            first_time = true;
        } else {
            std::cin.getline(fname, 20); //Also, whether or not this the first_time, use std::cin.getline() to fill in fname, up to twenty characters.
            }
    }
}
//
//right before exercise 3

///////////////////////////////////////
//lines 32-41 should be replacing array with ~ except for 
//the final char. 
int main() {
    char fname[20];
    bool first_time = true;
    while(1) {
    first_time = false;
    server(fname, first_time);
    client(fname, first_time);
    
    read_file(_global_mem, fname, mem_size);//////////
    for (int i = 0; i < mem_size; i++) {
        _global_mem[i] = '~';
        }
    _global_mem[mem_size - 1] = 0;
    
    }
}
/////////////////////////////////////// 