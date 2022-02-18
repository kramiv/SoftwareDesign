//out.yaml is the same as screen1.yaml written in add_yaml below - contains yaml info.
//out.mem is a few chars and then a bunch of ~. bytes of globalmem.
//debugging: we can look at out.yaml or out.mem manually to see what is being sent to the browser from the C++ code.
#include"../react.h"

int main() {//init(true), not init(), reads from cached_input intead of any message sent from client. run this file, then ./a.out to see in terminal intead of waiting for browser
  init();//receives message + stores in a file from browser
  //cached_input contains the yaml like screen1.yaml and it has 
  //a chunk that says "- event_info"
  //= info we sent to the browser and info about what has been happening in the client.
  //and out.mem sequence of bytes we sent out is sent back, mostly intact (~~~~~... missing)
  char state = _get_char(2);
  _put_raw(5, "hello");
  if (just_starting()) {
    state = 'h';
    _put_char(2, state);
  } else if (received_event()) {
    if (event_id_is("to_screen_two")) {//green --> to image with blue button
      state = 'T';
      _put_char(2, state);
    } else if (event_id_is("button_1")) {//yellow
      std::cerr << "ok!";
    } else if (event_id_is("to_home_screen")) {//blue --> take back to green and yellow button screen
      state = 'h';
      _put_char(2, state);
    }
  }
  if ('h' == state) add_yaml("home.yaml");
  else add_yaml("screen1.yaml");

  quit();//quit sends information back to bridge.py to client
  //and stores information in 2 files: out.yaml (contains yaml info.)
  //and out.mem(sequence of bytes globalmem)
}
