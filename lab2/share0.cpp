#include<iostream>//use cout and cin


int main() {
  char user_input[200];

  bool first_time = true;
  while(1) {
    if (first_time) {
      std::cout << "What is your name? ";
    } else {
      std::cout << "Ok, " << user_input << "\n";
    }
    first_time = false;
    std::cin.getline(user_input, 200);//reads the user's input
  }
}
//On line 1, we include iostream so that we can use cout and cin