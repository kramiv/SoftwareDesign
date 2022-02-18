

#include<iostream>
const int mem_size = 100;
char _global_mem[mem_size];

  // fill in code here
  //for i, get value of s[i]. put into _global_mem(i, s[i])
  //givens: array s
  //starting position in global mem is index
  //loop ends at null byte
//while loops don't have ; in them
///what does i start as?

void _put_raw(int index, char s[]) {
  int i;
  int len = 0;
  char carrot = 'a';//chars always have '' around them. "" is for string
  while (carrot != '\0') {//null character '\0' is a char
    carrot = s[len];///int = char
//    std::cout << len << std::endl;
    len++;//wait len will only get ++'ed once
  }
  for (i = 0; i < len - 1; i++) {
    _global_mem[index + i] = s[i];//5 6 7 8 9
  }
}

int main() {
  for (int i = 0; i < mem_size - 1; i++) {
    _global_mem[i] = '~';
  }
  _global_mem[mem_size - 1] = 0;
  char input[] = "hello";
  int index = 5;
  _put_raw(index, input);//replace ~~~~ starting at 5
  std::cout << (_global_mem) << std::endl;//show global_mem starting at 3
  // output should be ~~hello
}
