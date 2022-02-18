#include<iostream>
//okay I'm having a bunch of errors with get_friend
//not sure where that's from. Something to fix later.
class Measurement {
  int weight;
  int age;

public:
  Measurement(int w, int a) { 
    weight = w;
    age = a;
  }
  
  int get_weight() { 
    return weight; 
  }
};
 


class Human {
  Measurement m;
  Human *friend;
public:
  Human(int lbs, int years): m(lbs, years) { }

  Human *get_friend() { 
    return friend; 
  }

  void set_friend(Human *b) {  
    friend = b; 
  }

  int get_age() { 
    return m.get_age(); 
  }
};
 
int main() {
  Human h1(5, 10), h2(15, 25);
  h1.set_friend(&h2);
  h2.set_friend(&h1);
 
  int result = h1.get_friend()->get_age(); 
  std::cerr << result << std::endl; 
  result = h1.get_friend()->get_weight(); 
  std::cerr << result << std::endl;

}