#include "DVDArrayP.h"
//#include "DVD0.h"

//#include "DVD0.cpp"
//ask about dereferencing pointer in array inside of the display function.
//put class DVD into DVD.h file and include that intsead.
//DVD.cpp file for longer methods
/*
elt holds array (sz long) that holds pointer
to DVD

*/



//is my error in my DVD = operator?
//
//fix
DVDArrayP &DVDArrayP::operator=(const DVDArrayP &d) {
        //std::cerr << "operator= output:" << "\n";
        for (int i = 0; i < size; i++) {//delete non-0 elt[i]
            if ( elt[i] == 0) {
                std::cerr << elt[i] << "\n";
                continue;
            } else {
                //std::cerr << elt[i] << "\n";//prints actual pointer value/address that are printed as hex values (stored in bits)
                delete elt[i];//after loop: delete stuff pointed to
            }//by elt and then delete array elt
        }
        //delete origin array for organization 
        //before refilling it
        delete [] elt;//currently points to nothing//delete elt
        size = d.size;
        elt = new DVD*[size];//created an empty array of d.size long.
        //change loop so that it does not stop at 0
        for (int i = 0; i < d.size; i++) {
            if (d.elt[i] != 0) {
                elt[i] = new DVD;//create new DVD at each array element
                *(elt[i]) = *(d.elt[i]);//set DVD equal to d.DVDs

//is there an error in my DVD0.cpp operator= function? I take an existing
//DVD object without deleting its arrays and can just set them equal?
//void 
                } else {
                    elt[i] = 0;
                }
            }
        return *this;
    }

int DVDArrayP::Default_Size = 5;

DVDArrayP::DVDArrayP(const DVDArrayP &d) {//copy contsructor
//copy constructor works when there hasn't been anything allocated
//to it before.
//DVDArrayP c1;
//DVDArrayP c2(c1(c3)); would not work becaues c1 already exists
//DVDArrayP c2(c1);//create c2. Copy constructor creates one object
//copy constructor is a constructor for a new obj
//assignment operator takes an obj with existing values, clears them out, 
//and then recreates it
        size = d.size;
        elt = new DVD*[size];
        for (int i = 0; i < size; i++) {//avoid destructor errors
            if (d.elt[i] == 0) {
                elt[i] = 0;
            } else {
                //elt[i] = new DVD;
                //*(elt[i]) = *(d.elt[i]);//I haven't allocated a DVD yet for this to work
                //or:
                elt[i] = new DVD(*(d.elt[i]));//copy constructor
//at elt[i], it then points to a nameless DVD. 
            }//When I delete elt, then the destructor for DVD is automatically called
        }
    }

void DVDArrayP::display() {
        for (int i = 0; i < size; i++) {
            if (elt[i] != 0) {//need to derefernce elt[i] for id, title, and director
                std::cerr << i << ":    ";
                (*(elt[i])).display();
            }
        }
    }
DVDArrayP::DVDArrayP() {//default constructor
//everything that I create, I should delete. symmetry
        size = Default_Size;
        elt = new DVD*[size];
        for (int i = 0; i < size; i++) {
            elt[i] = 0;
        }
    }
DVDArrayP::DVDArrayP(int sz) {//constructor
        size = sz;
        //elt = array of sz long elt** -> (all 0 initially) pointer* -> DVD
        elt = new DVD*[size];
        for (int i = 0; i < size; i++) {
            elt[i] = 0;
        }
    }

DVDArrayP::~DVDArrayP() {
        for (int i = 0; i < size; i++) {
            if ( elt[i] == 0) {
                continue;
            } else {
                delete elt[i];//deletes the DVD. It 
//lets go of the memory to DVD which then automatically calls destructor for DVD
            }
        }
        delete [] elt;
    }
//ask about deleting array in memory diagram - cross out?
DVD &DVDArrayP::operator[](int i) {//I am returning a DVD reference, not a DVD
//DVD reference is a DVD.
//it is called a reference - am I giving back a copy of the object or the object itself
//add nested for for normal i
    //delete stuff:

    std::cerr << "operator[] output:" << "\n";
        if (i < 0) {
            std::cerr << "error. i not in range \n";
            if (elt[0] == 0) {
                elt[0] = new DVD;//what if 0 has something in it?
            }//use default constructor
        return *(elt[0]);
        } else if (i > (size - 1)) {
            std::cerr << "error. i not in range \n";
            if (elt[(size - 1)] == 0) {
                elt[(size - 1)] = new DVD;//what if 0 has something in it?
            }
        return *(elt[(size - 1)]);
        } else {
            if (elt[i] == 0) {
                elt[i] = new DVD;
            }
        return *(elt[i]);
        }   //I don't always need an else with an if-statment (if "not in loop", remove it)
    }//return *(elt[i]);//it will access elt of -1