//writes into a file
//create new fstream object
//read it back out
#include<iostream>
#include<fstream>
int main() {
  std::ofstream f("output.txt");
  f << "Hello world!" << std::endl;
  f.close();

  std::ifstream f1("output.txt");
  char array[12];
  f1 >> array;
  char array2[12];
  f1 >> array2;
  std::cerr << array << array2;
  //f.close();
}
