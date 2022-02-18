#include<iostream>
#include<fstream>
#include <stdio.h>
char fname[] = "/usr/local/cs/cs251/chat/data/Ivana.txt";
char *_global_mem;
//author and msg don't have null bytes at the end
void _put_raw(int index, const char s[]) {//
  int i;
  int len = 0;
  char carrot = 'a';
  while (carrot != '\0') {
    carrot = s[len];
    len++;
  }
  for (i = 0; i < len - 1; i++) {//i less than or equal to len. It would go through the loop
  //once more and copy the loop into _global_mem
    _global_mem[index + i] = s[i];//9 10 11 (12 = null)
  }
  //_global_mem[len] = '\0';//20 21 22 23 24 25 26... (null)
  _global_mem[(len - 1) + index] = '\0';////test using tiny arrays. test_put_raw.
  //hello: len = 6
  //null byte at 5 in global mem
  //re-add null byte at 5.
//copying strings: sometimes, prof has added a null byte explicitly and other times not.
//he is doing it implicitly: ex. changing the guard in the loop
//in my loop for copying the chars:
///i less than or equal to len. It would go through the loop
  //once more and copy the loop into _global_mem
}

void write_message(int index, const char author[], const char msg[]) {
    //_put_raw(index + 19, "\0");
    //_put_raw((index + 98), "\0");
    _put_raw((index + 9), author);
    _put_raw((index + 20), msg);
}

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
  array[num_bytes] = '\n';
}

void read_file(char fname[], char array[], int max_size) {
  std::ifstream f(fname);
  read_stream(f, array, max_size);
  //std::cerr << fname << std::endl;
  f.close();
}

void display_messages(int num_messages) {
  int offset = 100*num_messages;
  std::cerr << "author: " << _global_mem + 9 + offset << " message: " << _global_mem + 20 + offset << '\n';
  std::cerr << '\n';
}

int main(int argc, char **argv) {
    _global_mem = new char[10000];
    read_file(fname, _global_mem, 10001);
    //edited global mem
    _global_mem[10] = '\0';
   if ((argc-1) == 0) {
        std::cerr << "Usage: ./chat1 username " << "\n"; 
    } else {
        while (true) {
        char message[80];
        char *username = argv[1];
        std::cerr <<  username << "> ";
        std::cin.getline(message, 80);

        read_file(fname, _global_mem, 10001);
        unsigned char num_messages = _global_mem[10];
        num_messages++;
        _global_mem[10] = num_messages;

        int index = 100*num_messages;
        write_message(index, username, message);

        std::ofstream f(fname);
        f.write(_global_mem, 10000);
        f.close();
        std::cerr << static_cast<int>(num_messages) << "\n";
        ///////////////////
        display_messages(num_messages);
    }
  }
}

