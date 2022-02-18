//exercise 10: initialize contents of shared file.
//I may not read_file stuff in here

#include<iostream>
#include<fstream>
#include <stdio.h>//for delete_file function
//put read_file physically below read_stream. 

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
char fname[] = "/usr/local/cs/cs251/chat/data/Ivana.txt";
char *_global_mem;//pointer to a sequence of bytes
void read_file(char fname[], char array[], int max_size) {
  std::ifstream f(fname);
  read_stream(f, array, max_size);
  std::cerr << fname << std::endl;
  f.close();
}


int main(int argc, char **argv) {
    _global_mem = new char[10000];
    _global_mem[10] = '\0';

    for (int i = 0; i < 10000; i++) {//initialize global_mem to ~:
      _global_mem[i] = '~';
   }
    for (int i = 99; i < 10000; i = i + 100) {
      _global_mem[i] = '\n';
    }

    //read_file(fname, _global_mem, 10001);
    _global_mem[10] = '\0';

    //read_file(fname, _global_mem, 10001);

    std::ofstream f(fname);
    f.write(_global_mem, 10000);
    f.close();
}
//this only works if I put it up here. not sure why.
//place initialized _global_mem into file
/*
   if ((argc-1) == 0) {
        std::cerr << "Usage: ./chat1 username " << "\n"; 
    } else {
      while (true) {
      unsigned char num_messages = _global_mem[10];//num messages = global mem 10
      char message[80];
      char *username = argv[1];
      std::cerr <<  username << "> ";
      std::cin.getline(message, 80);
      num_messages++;
      _global_mem[10] = num_messages;
      std::ofstream f(fname);
      f.write(_global_mem, 10000);
      std::cerr << static_cast<int>(num_messages) << "\n";//convert char to int for printing
    }
    */

//to share message information,
//write it into ivana.txt
//and read it back into file
//to see how others have written
//it.
//read and write into the file inside
//of the loop.

//get read_file() and read_stream() functions
//paste them into chat2 before any function that uses them
//remove loops that initialize _global_mem and read that info from my shared 
//file: replace with read_file(fname, _global_mem, 10001);
//make sure that _global_mem[10] is still a 0 or null byte (see above)



//convert file contents to a char sequence, shipping it out.
//also seeing how to ship stuff back in.
//create _global_mem (sequence of bytes)
//initialize a shared file
//read_global_mem from shared file
//make these operations part of the loop
//test in two windows + test with partner.