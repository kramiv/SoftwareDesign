#include<iostream>
#include<fstream>
#include <stdio.h>//for delete_file function
//exercise 15: it worked
char fname[] = "/usr/local/cs/cs251/chat/data/Ivana.txt";
char *_global_mem;//pointer to a sequence of bytes

void read_stream(std::istream &f, char array[], int max_size) {
  int num_bytes;
  if (f.good()) {
    f.read(array, max_size);
    if (f) {
      std::cerr << "Warning in read_stream: did not reach end of stream after " << max_size << " characters.";
      num_bytes = max_size - 1;
    } else {
      num_bytes = f.gcount();
      if (num_bytes >= max_size) num_bytes = max_size - 1;
    }
  } else {
    std::cerr << "Warning in read_stream: unable to read anything\n";
    num_bytes = 0;
  }
  array[num_bytes] = '\n';  // assign null at end
}

void read_file(char fname[], char array[], int max_size) {
  std::ifstream f(fname);
  read_stream(f, array, max_size);
  //std::cerr << fname << std::endl;
  f.close();
}


int main(int argc, char **argv) {
    _global_mem = new char[10000];//create global mem
    read_file(fname, _global_mem, 10001);//read fname into global mem
    //edited global mem
    _global_mem[10] = '\0';//global mem 10 is null byte. could be = 0;
   if ((argc-1) == 0) {//if usage is blank, output this. 
//./a.out is executable. after the name of the executable, "amy" is command line argument.
//arguments to the program. to see those arguments, we have argc adn argc** that hold
//the command line arguments. argv = array of strings with null byte
//if we have an array, we want the size. 
//argc = size of array.
//argc - 1 checks to see if the user typed in just the name of the program + nothing else
//counts the # of things after the executable. with "amy", argc = 2
        std::cerr << "Usage: ./chat1 username " << "\n"; 
    } else {//if usage is correct, this loop starts
        while (true) {
        char message[80];//message is 80 chars
        char *username = argv[1];//
        std::cerr <<  username << "> ";
        std::cin.getline(message, 80);//wait for user input after username

        read_file(fname, _global_mem, 10001);//reads bytes into global mem
        unsigned char num_messages = _global_mem[10];
        num_messages++;
        _global_mem[10] = num_messages;//update global_mem at 10
        std::ofstream f(fname);
        f.write(_global_mem, 10000);//write in modified global mem
        f.close();
        std::cerr << static_cast<int>(num_messages) << "\n";//convert type
        }
    }
}
//run amy, run bob, amy says "hi"
//when we run bob, amy hasn't said "hi" yet

//RUN AMY:
//x = 0;
//_global_mem[10] = x;
//num_messages = x;

//RUN BOB:
//_global_mem[10] = x;
//num_messages = x;

//AMY: "hi"
//num_messages = x + 1;
//_global_mem[10] = x + 1;

//BOB: "hi"
//num_messages = x + 1;
//_global_mem = x + 1;

//at what point should I read from the file to update bob or amy's information?
//before they speak for sure.






//BOB:
//_global_mem[10] = x + 1;
//num_messages = x + 1;

//if we run bob before typing "hi" for amy





//_global_mem[10] = x + 1;
//num_messages = x + 1;
//

//amy>
//line 54 stops: num_messages = '\0' = 0.
//amy > hi
//num_messages = 1
//1 should be the 10th element of global mem and of our file
//num_messages = 1

//bob: 
//line 54 stops: num_messages = '\0' = 0.
//bob> hi
//num messages = 0, globalmem[10] = 1

    /*
    for (int i = 0; i < 10000; i++) {//initialize global_mem to ~:
      _global_mem[i] = '~';
   }
    for (int i = 99; i < 10000; i = i + 100) {
      _global_mem[i] = '\n';
    }
*/