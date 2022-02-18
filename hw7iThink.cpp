//I'm not sure what to enter in the terminal to make this work.

#include<iostream>

float convert_to_celcius(float fahrenheit) {
  return (5./9.)*(fahnrenheit - 32.);
}  

int main() {
  if (convert_to_celcius(32.) == 0.) 
    std::cerr << "yes" << std::endl;
  else
    std::cerr << "no" << std::endl;
  if (convert_to_celcius(-40.) == -40.) 
    std::cerr << "yes" << std::endl;
  else
    std::cerr << "no" << std::endl;
}
