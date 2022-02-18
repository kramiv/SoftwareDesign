#include"../show_mem.h"
#include"../show_mem.h"
#include"../show_mem.h"
int main() {
  int i;
  int n;
  for (i = 0; i <= 100; i = i + 2) {
    if (i % 5 == 0)
      continue;
    else
      n = i / 2;
  }//semicolon here not needed: use it at the end of a statment. (note if, continue, else here)
}

//return("i"); is used only once main() is all done