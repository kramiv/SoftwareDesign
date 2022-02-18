#include"../react.h"

void make_button(int i, unsigned char *array) {
    int r = array[3*i + 0];//
    int g = array[3*i + 1];
    int b = array[3*i + 2];
    int r2 = array[3*(i) + 0] + 50;
    int g2 = array[3*(i) + 1] + 50;
    int b2 = array[3*(i) + 2] + 50;
    add_yaml("button.yaml", {{"id", i}, {"r", r}, {"g", g}, {"b", b}, {"r2", r2}, {"g2", g2}, {"b2", b2}});
}

void handle_button(int button) {
    std::cerr << "value of button: " << (button + 1) << '\n';
}

int main() {
    int num_moves;
    const int num_colors = 6;
    init();
    if (just_starting()) {
  add_yaml("flood_fill.yaml");
    int num_moves = 0;
    _put_int(123, num_moves);
    unsigned char button_colors[18] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170};
  for (int i = 0; i < num_colors; i++) {
      make_button(i, button_colors);
  }
    } else if (received_event()) {
    num_moves = _get_int(123);
    add_yaml("flood_fill.yaml");
    unsigned char button_colors[18] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170};
    for (int i = 0; i < num_colors; i++) {
    make_button(i, button_colors);
    }
    for (int i = 0; i < num_colors; i++) {
    if (event_id_is("button_", i)) {
        handle_button(i);
        num_moves++;
        }
    }
    }
    _put_int(123, num_moves);
    std::cerr << "num moves: " << num_moves;
    quit();
}
