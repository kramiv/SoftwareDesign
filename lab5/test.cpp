#include<fstream>
int main() {
  std::ofstream f1("myfile.txt");
  f1.write("hello\n", 6);
  char a = 'K';
  f1 << a << std::endl;
  short b = 9;
  f1 << b << std::endl;
  float d = 1.1;
  f1 << d << std::endl;
}
