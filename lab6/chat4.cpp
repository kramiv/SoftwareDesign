//need to go over exercise 20
//see how to run it
//https://docs.google.com/document/d/1ua1znG9qDzvabWst3l6E6-YKsAGA1LWArseXDinBL8M/edit
//and find out why I am missing .yaml file and out.mem file

#include<iostream>
#include<fstream>
#include<stdio.h>
#include"../react.h"
char fname[] = "/usr/local/cs/cs251/chat/data/Ivana.txt";

void write_message(int index, const char author[], const char msg[]) {
    _put_raw(index, time_of_day(current_time()));
    _put_raw((index + 9), author);
    _put_raw((index + 20), msg);
}

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
  array[num_bytes] = '\n';
}


void read_file(char fname[], char array[], int max_size) {
  std::ifstream f(fname);
  read_stream(f, array, max_size);
  f.close();
}

void display_messages(int num_messages) {
  int offset = 100*num_messages;
  
  ////////////////"to make the messages bubbles"
  add_yaml("bubble.yaml", {{"time_index", 0 + offset}, {"author_index", 9 + offset}, {"msg_index", 20 + offset}, {"indent", 50}});//brings in bubble.yaml
  /*
  int time_index = _global_mem + offset;//time at 0 + offset, author at 9 + offset, message 20 + offset
  int author_index = _global_mem + 9 + offset;
  int msg_index = _global_mem + 20 + offset;
  */
  //int indent = 50;//not sure what to do with this
  //std::cerr << " time: " << _global_mem + offset  << " author: " << _global_mem + 9 + offset << " message: " << _global_mem + 20 + offset << '\n';
  //std::cerr << '\n';
}

int main(int argc, char **argv) {
    char num_messages;
  if (just_starting()) {
    _global_mem[10] = '\0';
  } else if (received_event()) {
    char *a;
    a = &num_messages;
    //char message[80];
    //std::cerr <<  username << "> ";//prints username
    //std::cin.getline(message, 80);
    char *message = _global_mem + get_event_index();
//"please continue to use message to check for zero length
//messages and then for calling write_message
//username = get_user_name()
    *a = _global_mem[10];
    *a++;
    _global_mem[10] = *a;
//Please continue to use message to check for 
//zero-length messages and then for calling write_message. ??
    int index = 100*(*a);
    const char *username = get_user_name();
    write_message(index, username, message);
    //std::cerr << static_cast<int>(num_messages) << "\n";
  }
  std::cerr << static_cast<int>(num_messages) << "\n";
  display_messages(num_messages);//either keep this here or make num_messages a reference


  init();//add a call to "init" that sets up _global_mem with information to the browser
    //_global_mem = new char[10000];//this code is part of init() now
  add_yaml("scrollable.yaml");//bring in the scrollable.yaml file which contains View descriptions for bubbles of text

  const int text_input_index = 20;
  add_yaml("end_input.yaml", {{"index", text_input_index}});//bring in the end_input.yaml file which contains the TextInput that the user will see.
  _put_raw(text_input_index, "", 0);//check
/*
In file included from chat4.cpp:9:
../react.h:115:6: note: declared here
 void _put_raw(int index, const char *raw_string, bool shared=false);
 */
//store empty string at index given by t_i_i
//to clear it out each time textinput is sent to 
//the server
  quit();//sends _global_mem back to the browser
}



/*

#include<iostream>
#include<fstream>
#include<stdio.h>
#include"../react.h"
char fname[] = "/usr/local/cs/cs251/chat/data/Ivana.txt";
//char *_global_mem;
//author and msg don't have null bytes at the end
/*
void _put_raw(int index, const char s[]) {//
  int i;
  int len = 0;
  char carrot = 'a';
  while (carrot != '\0') {
    carrot = s[len];
    len++;
  }
  for (i = 0; i < len - 1; i++) {//i less than or equal to len. It would go through the loop
  //once more and copy the loop into _global_mem
    _global_mem[index + i] = s[i];//9 10 11 (12 = null)
  }
  //_global_mem[len] = '\0';//20 21 22 23 24 25 26... (null)
  _global_mem[(len - 1) + index] = '\0';////test using tiny arrays. test_put_raw.
}

void write_message(int index, const char author[], const char msg[]) {
    _put_raw(index, time_of_day(current_time()));
    _put_raw((index + 9), author);
    _put_raw((index + 20), msg);
}

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
  array[num_bytes] = '\n';
}


void read_file(char fname[], char array[], int max_size) {
  std::ifstream f(fname);
  read_stream(f, array, max_size);
  //std::cerr << fname << std::endl;
  f.close();
}

void display_messages(int num_messages) {
  int offset = 100*num_messages;
  std::cerr << " time: " << _global_mem + offset  << " author: " << _global_mem + 9 + offset << " message: " << _global_mem + 20 + offset << '\n';
  std::cerr << '\n';
}

int main(int argc, char **argv) {
    _global_mem = new char[10000];
    read_file(fname, _global_mem, 10001);
    //edited global mem
    _global_mem[10] = '\0';
   if ((argc-1) == 0) {
        std::cerr << "Usage: ./chat1 username " << "\n"; 
    } else {
        while (true) {
        char message[80];
        char *username = argv[1];
        std::cerr <<  username << "> ";
        std::cin.getline(message, 80);

        read_file(fname, _global_mem, 10001);
        unsigned char num_messages = _global_mem[10];
        num_messages++;
        _global_mem[10] = num_messages;

        int index = 100*num_messages;
        write_message(index, username, message);

        std::ofstream f(fname);
        f.write(_global_mem, 10000);
        f.close();
        std::cerr << static_cast<int>(num_messages) << "\n";
        ///////////////////
        display_messages(num_messages);
    }
  }
}
*/

