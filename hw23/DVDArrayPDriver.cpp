#include<iostream>
#include"DVDArrayP.h"
//#include"DVD0.h"

//#include "DVD0.cpp"
/*
DVDArrayPDriver, the executalbe, needs to be recreated
whenever any of the .o files change.
if a .h file changes, then the .o file will be recompiled too.
Then, that will trigger having a new executable.

DVDArrayPDriver:  DVDArrayP.o DVDArrayPDriver.o 
	g++ -g -Wall -o DVDArrayPDriver DVDArrayP.o DVDArrayPDriver.o

DVDArrayP.o:  DVDArrayP.cpp DVDArrayP.h DVD0.h
	g++ -g -Wall -c DVDArrayP.cpp
	
DVDArrayPDriver.o:  DVDArrayPDriver.cpp DVDArrayP.h DVD0.h
	g++ -g -Wall -c DVDArrayPDriver.cpp
  
*/
int main() {
  DVDArrayP arr1, arr2(5);
  std::cerr << "arr1 has size " << arr1.getSize() << std::endl;//works
  arr2.display(); std::cerr << std::endl;//works = nothing
 
  DVD d1(1, "Gandhi", "Richard Attenborough");//1 movie is filled
  arr2[1] = d1;//this is a function call. gives DVD//set arr[1]
//arr2.elt[1] is a pointer
  arr2.display(); std::cerr << std::endl;//display it: get 1 movie
  arr2[389]; // should display an error, but not crash.//it should create an array at 4
    //  in this case, arr2[389] default-constructs element arr2[4]
  arr2.display(); std::cerr << std::endl;
 
  DVDArrayP arr3(arr2);
  arr3.display();
  arr1 = arr2;
  arr1.display();
  DVD d2(8, "The Fellowship of the Ring", "Peter Jackson");
  arr2[2] = d2;
  (arr1 = arr2)[0] = d2;
  arr1.display();
}
