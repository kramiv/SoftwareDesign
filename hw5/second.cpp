#include"../show_mem.h"

int main() {
    // print a prompt for the user
  _put_raw(0, "What is your name? ");
  _print_raw(0);

    /*
        To be able to print Hello next to the user's name,
        we place their name right after Hello in _global_mem.
    */
  _put_raw(0, "Hello, ");
  _user_input(7);
  _print_raw(0);
}