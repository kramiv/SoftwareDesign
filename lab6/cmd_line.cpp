//argv is a pointer to a pointer. not sure why.
#include<iostream>

int main(int argc, char **argv) {
  std::cerr << "The program name is " << argv[0] << "\n";
  std::cerr << "You typed in " << (argc-1) << " arguments:\n";
  for (int i = 1; i < argc; ++i) {
    std::cerr << "\t" << argv[i] << "\n";
  }
}//why were argc and argv chosen?
//argc - 1: why?
//command lines 1, 2, and 3 are all strings with a null byte.
//argc is the length of the 1, 2, and 3.

//argv[0] is the name of the argument.
//if (argc) == 2:
    //argc = Otherwise, call the one command line argument the 
    //username (make it a char *), and print the username
    // followed by a >.  
//else: "you typed in (argc-1) arguments" + for loop on line 7 here

