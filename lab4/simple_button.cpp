#include"../react.h"
  
int main() {
  init();//receive communication from browser
  //make buttons have response when clicked by user (if loops below):
  if (received_event()) {//check to see if browner sent information about a user event to this .cpp
    if (event_id_is("go")) {
      std::cerr << "Stop!\n";
    } else if (event_id_is("stop")) {
      std::cerr << "Go!.\n";
    }
  }

  add_yaml("green_red.yaml");//load the text file

  quit();//send communication back to browser
}
