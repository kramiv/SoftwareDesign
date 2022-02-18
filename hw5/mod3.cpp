#include"../show_mem.h"

int main() {
  _put_raw(0, "Choose 1 or 2: . It is nom nom time and you go to the caf.  go to -main food line- 2 or to -grains- 1 line in caf? ");
  _print_raw(0);
  _user_input(0);

  if ('1' == _get_char(0) ) { // compare character
    _put_raw(0, "You chose the grains line. Do you want beans 1 or lentils 2? ");
    _print_raw(0);
    _user_input(0);
        if ('1' == _get_char(0)) {
            _put_raw(0, "the beans made you fart");
            _print_raw(0);
        } else {
            _put_raw(0, "the lentils were tasty");
            _print_raw(0);
        }
    // we could put more code here!

  } else {
    _put_raw(0, "main food line. Do you want salad 1 or a sandwich 2? ");
    _print_raw(0);
    _user_input(0);
        if('1' == _get_char(0)) {
            _put_raw(0, "the salad tasted like it'd been sitting out all afternoon...");
            _print_raw(0);
        }
        else {
            _put_raw(0, "the sandwich was just stuffed with the salad. Is that even a sandwich?");
            _print_raw(0);
        }
    // or here!
  }
}