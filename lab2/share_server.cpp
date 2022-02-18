#include<iostream>//use cout and cin
#include <fstream>//read file stream?
#include <stdio.h>//for delete_file function
//comments:
//input1.txt: this file seems broken.
//In VScode, take a look at the .response file.  It should be filled with lots of ~ characters (from _global_mem), but at the beginning (at about the twentieth character) we should see "What file would you like? ".  Let's try another test:
//^^for this line above, I only get ~~~~hello~~~~~~~~>
//yeah neither does the next test after it.
//the terminal's output for the 2nd test *did* change .response  ("This time, when we look at the .response file, beginning at about the twentieth character, we should see the contents of the a.txt file!")





const int mem_size = 10000;//has to be const to work
char _global_mem[mem_size];//it is 10,000 chars (abcd...)


////////////////////////////////
void delete_file(const char *fname) {
  remove(fname);
}
////////////////////////////////

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

void read_file(char fname[], char array[], int max_size) {
  std::ifstream f(fname);
  read_stream(f, array, max_size);
  std::cerr << fname << std::endl;
  f.close();
}


void read_request() {///bottom of page 10: check
    read_file(".request", _global_mem, mem_size);///previosu error in converting string contsant to char (mem_size?)
    read_file("cached_input0", _global_mem, mem_size - 1);//line below intsructions
    f.write(_global_mem, mem_size - 1);// That is, in read_request(), please add two lines at the end of the function that write _global_mem to a file called cached_input0 (writing mem_size - 1 bytes).  Similarly, in write_response(), please add two lines that write _global_mem to a file called out0.mem (again writing mem_size - 1 bytes).  These files will be handy when we are testing our server in the context of using the client.
}
////////////////////////////////
void write_response() {
    std::ofstream f(".response");
    f.write(_global_mem, mem_size - 1);
    delete_file(".request");
    read_file("out0.mem", _global_mem, mem_size - 1);
    f.write(_global_mem, mem_size - 1);
 }

 ////////////////////////////////
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
///////////////////////////////////////
////////////////////////////////
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
}
////////////////////////////////

int main() {
    init_global_mem();
    read_request();//The read_request() function will be responsible for receiving information sent by the client (and then storing it in _global_mem).
    _global_mem[20] = 'X';
        if (_global_mem[20] == '~') {
        char a[] = "What file would you like?";
        _put_raw(_global_mem[21], a);
    } else {
        read_file(_global_mem, _global_mem + 21, mem_size - 21);
    }
    std::cin.getline(_global_mem, 20);
    write_response();
}