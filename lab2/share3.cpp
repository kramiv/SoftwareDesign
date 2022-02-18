#include<iostream>//use cout and cin
#include <fstream>//read file stream?
//#include "../show_mem.h"
const int mem_size = 10000;//has to be const to work
char _global_mem[mem_size];//it is 10,000 chars (abcd...)
///////////////////////////////////////
void _put_raw(int index, char s[]) {
  int i;
  int len = 0;
  char carrot = 'a';//chars always have '' around them. "" is for string
  while (carrot != '\0') {//null character '\0' is a char
    carrot = s[len];///int = char
//    std::cout << len << std::endl;
    len++;//wait len will only get ++'ed once
  }
  for (i = 0; i < len - 1; i++) {
    _global_mem[index + i] = s[i];//5 6 7 8 9
  }
}
///////////////////////////////////////
void read_stream(std::istream &f, char array[], int max_size) {
  int num_bytes;
  if (f.good()) {
    f.read(array, max_size);
    if (f) {
      std::cerr << "Warning in read_stream: did not reach end of stream after " << max_size << " characters.";
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
void server() {//modify the server() and client() functions so that there are no function parameters given.
//remove while loop with while(1) and bool
    _global_mem[20] = 'X';//This line changes one byte of _global_mem so that it is no longer a tilde, replacing the old first_time = false.
    if (_global_mem[20] == '~') {//removed first_time. == checks to see if stuff is equal
        //std::cout << "What file would you like? ";//in server(), instead of using cout for "What file would you like? ", use the _put_raw() function, and place the characters into _global_mem beginning at index 21.
        char a[] = "What file would you like?";///this string is literally in global_mem. Not sure if this is useful.
        _put_raw(_global_mem[21], a);
    } else {
        read_file(_global_mem, _global_mem + 21, mem_size - 21);//in server(), use _global_mem + 21, rather than just _global_mem, in the function call to read_file().  in the same read_file() call, reduce the maximum number of bytes to read by 21.
    }
    //first_time = false;
    std::cin.getline(_global_mem, 20);//reads the user's input
}
///////////////////////////////////////
void client() {//removed bool first_time
//remove while(1) using bool to remove first time (and in server())
    if (_global_mem[20] == '~') {//removed first_time
        std::cout << _global_mem + 21;//in client(), use cout to print (_global_mem + 21), rather than _global_mem.
        std::cin.getline(_global_mem, 20);
        //first_time = true;
    } else {
        std::cin.getline(_global_mem, 20); //Also, whether or not this the first_time, use std::cin.getline() to fill in fname, up to twenty characters.
        }
}
///////////////////////////////////////
void init_global_mem(){//not int because I don't return anything.
    char fname[20];///this varialbe is also in main() right now.
    read_file(_global_mem, fname, mem_size);//////////
    for (int i = 0; i < mem_size; i++) {
        _global_mem[i] = '~';
        }
//    _global_mem[mem_size - 1] = 0;
    ///main() contents for _put_raw function//////////
    //use _global_mem for fname, then next byte in _global_mem I'm assuming to store
    //what we previously named first_time. remaining bytes to store file contents.
    //one part is being used to store a filename, another part is being used to store 
    //a simple boolean, and another part is used to hold the contents of a file. 
    for (int i = 0; i < mem_size - 1; i++) {
    _global_mem[i] = '~';
    }
//    _global_mem[mem_size - 1] = 0;
    char input[] = "hello";
    int index = 5;
    _put_raw(index, input);//replace ~~~~ starting at 5
}//Move the code we have right now at the beginning of main() into the init_global_mem() function, and call that function to initialize the memory for _global_mem.  Check that your code still works (compile and test).
///////////////////////////////////////
//lines 32-41 should be replacing array with ~ except for 
//the final char. 
int main() {//remove fname[20]
    init_global_mem();//CHECK if this should be up here
    while(1) {
    //bool first_time = false;
    server();//////////
    client();//////////std::cin.getline(_global_mem, 20)
    std::cout << (_global_mem) << std::endl;//show global_mem starting at 3
    }
}
/////////////////////////////////////// 