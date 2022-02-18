#include<iostream>//use cout and cin
#include <fstream>//read file stream?
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
void read_file(const char fname[], char array[], int max_size) {
  std::ifstream f(fname);
  read_stream(f, array, max_size);
  f.close();
}
///////////////////////////////////////
int main() {
  char fname[20];
  char content[1000];
  bool first_time = true;
  while(1) {
    if (first_time) {
      std::cout << "What file would you like? ";
    } else {
      //read from fname into array content with
      //appropriate maximum of bytes.
//Verify that you can ask for multiple files, and that they are shown correctly in the terminal.
      read_file(fname, content, 1000);//00000000000000000CHECKHERE
    ///std::cout << "Ok, " << content << "\n";
    }
    first_time = false;
    std::cout << content << std::endl;//like cerr: 
    std::cin.getline(fname, 20);//reads the user's input
  }
}
//On line 1, we include iostream so that we can use cout and cin
///////////////////////////////////////