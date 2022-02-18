  #include"../react.h"

int main() {
  init();
  char state = _get_char(2);
  _put_raw(5, "hello");
  if (just_starting()) {
    state = 'h';
    std::cerr << "this is the home page. Select option A or B";
    _put_char(2, state);
  } else if (received_event()) {
    if (event_id_is("to_option_a")) {//green --> to image with blue button
      state = 'a';
      _put_char(2, state);
      std::cerr << "You have chosen option A. Choose A1 or A2.";

    } else if (event_id_is("to_option_b")) {//yellow
      state = 'b';
      _put_char(2, state);
      std::cerr << "You have chosen option B. Choose B1 or B2.";

    } else if (event_id_is("to_option_a1")) {//blue --> take back to green and yellow button screen
      state = 'a1';
      _put_char(2, state);
      std::cerr << "You have chosen option A1.";


    } else if (event_id_is("to_option_a2")) {//blue --> take back to green and yellow button screen
      state = 'a2';
      _put_char(2, state);
      std::cerr << "You have chosen option A2.";

    } else if (event_id_is("to_option_b1")) {//blue --> take back to green and yellow button screen
      state = 'b1';
      _put_char(2, state);
      std::cerr << "You have chosen option B1.";

    } else if (event_id_is("to_option_b2")) {//blue --> take back to green and yellow button screen
      state = 'b2';
      _put_char(2, state);
      std::cerr << "You have chosen option B2.";

    }
  }
  if ('h' == state) add_yaml("homepage.yaml");
  if ('a' == state) add_yaml("screena.yaml");
  if ('b' == state) add_yaml("screenb.yaml");
  if ('a1' == state) add_yaml("screena1.yaml");
  if ('a2' == state) add_yaml("screena2.yaml");
  if ('b1' == state) add_yaml("screenb1.yaml");
  if ('b2' == state) add_yaml("screenb2.yaml");
  //either homepage or the page with image
  quit();
}