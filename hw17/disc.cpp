#include<iostream>
//this is also not working (note.cpp not working. line 26 here -
//both .ccps' functions have issues here.)
class UltimateFrisbee {
  int size;
  float *data;
public:
  UltimateFrisbee() { size = 0; data = 0; }
  UltimateFrisbee(int s) { size = s; data = new float[size]; }
  UltimateFrisbee(const UltimateFrisbee &b) {
      size = b.size;
      data = new float[size];
      for (int i = 0; i < size; i++) {
          data[i] = b.data[i];
      }
  }

  ~UltimateFrisbee() {
    std::cerr << "bye!" << std::endl;
    if ( data ) delete [] data;
  }

  void display()
    { std::cerr << "size " << size << std::endl;}
};

void f(UltimateFrisbee d) {
    d.display();
}

int main()
{
  UltimateFrisbee g1, g2(3);

  g1.display();
  g2.display();
  f(g1);
}
