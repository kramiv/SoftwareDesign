#include<iostream>
#include<stdlib.h>

/*This can be used as a sort of template for any randomization we need, can be
modified to generate numbers in a different range. We can use this for dungeon 
generation, item generation, gold dropped on enemy death, or really anything
that we could think to implement*/
int main() {
    int num;
    //resets randomization for a different list every time
    srand (time(NULL));
    for(int i= 0; i<10; i++) {
        /*generates a list of random numbers 1-10. the second number(1 below) is
        the lower bound, while the upper bound is the sum of the numbers minus 1
        */ 
        num= rand()%10+1;
        std::cerr<<num<<std::endl;
    }
}