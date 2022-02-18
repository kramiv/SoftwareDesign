#include<string>
#include<iostream>
int main() {
    std::string s = "aa";
  //std::cerr << s[1] << std::endl;  
  //std::cerr << "size " << s.size() << '\n' << std::endl;
  //s.insert(s.begin() + 1, 'i');
  //std::cerr << s << '\n';

    //s = s + " ok";
  //std::cerr << s << std::endl; 
  std::string s2 = "a";
  std::cerr << (s < s2) << std::endl;//s2 should come later than s
//alphabetical
}


/*
 for (auto x : arr)
    std::cerr << x << std::endl;
auto x has already been declared as int &x, so 'redeclaring' x just makes it whatever type the previous x was?
 = 
*/