//fix

#include<iostream>
//note: arg1, arg2 in Rating. 
//how state variables are called in all funstions + main.
class Rating {//class with state variables inside
    int id;
    int stars;
};
//initialize object's state variables:  p2.init(false, 11, 9);
//(the class's variables)
public:
    Rating(int arg1, int arg2) {//constructor
        id = arg1;
        stars = arg2;//series of if
    }
int set_stars(int a) {
    stars = a;
    //series of if
    return stars;
}
void get_id() {
    return id;
}

void get_stars() {
    return stars;
}
void display(std::ostream& review) {
    //print # of stars
  char asterisk = new char[stars];
  for (int i = 0; i < stars; i++) {
    asterisk[i] = "*";
  }
  review << id << ":" << asterisk[];
}

//void function(std::ostream& review) {
//    review << "yummy cake" << endl;
//}

int main() {
  Rating r(1234, 3);
  std::cerr << "Rating r contains ";   
  r.display(cout);  
  std::cerr << std::endl;
  r.set_stars(4);
  std::cerr << "After r.set_stars(4), id=" << r.get_id() 
       << " and stars=" << r.get_stars() << std::endl;

  //Rating *arr[8];
  //int i;
  //for (i = 0;  i < 8;  i++) {
  //  arr[i] = new Rating(100+i, i);
  //}
  //std::cerr << "Ratings in array arr:  ";
  //for (i = 0;  i < 8;  i++) {
  //  arr[i]->display(cout); std::cerr << "  ";
  }
  std::cerr << std::endl;    
}