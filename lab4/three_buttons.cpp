#include"../react.h"
  
int main() {
  init();
  if (received_event()) {//check to see if browner sent information about a user event to this .cpp
    if (event_id_is("go")) {
      std::cerr << "Stop!\n";
    } else if (event_id_is("stop")) {
      std::cerr << "Go!.\n";
    } else if (event_id_is("toe")) {
      std::cerr << "Toe!.\n";
    }
  }
  add_yaml("three_buttons.yaml");

  quit();
}
