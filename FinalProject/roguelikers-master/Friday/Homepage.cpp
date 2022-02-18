#include"../../react.h"
//https://docs.google.com/document/d/1TWMzyyjqIvhJYJibgPuAf85RuTrToCqpTUxUf8t2X3E/edit
//1900*900
//think about how to compile all the pges together
//I will need position of the player and update it. 
//
void hubtext() {
    _put_raw(0, "Upgrades Shop");
    _put_char(14 , 0);
    _put_raw(15, "Clothing Shop");
    _put_char(28, 0);
    _put_raw(29, "Dungeon Entrance");
    _put_char(45, 0);
}

void homepagetext() {
    _put_raw(0, "Roguelikers");
    _put_char(11, 0);
    _put_raw(12, "Select New Run");
    _put_char(26, 0);
    _put_raw(27, "Select Previously Saved Run");
    _put_char(54, 0);
    _put_raw(55, "Run 1");
    _put_char(60, 0);
    _put_raw(61, "Run 2");
    _put_char(66, 0);
    _put_raw(67, "Run 3");
    _put_char(72, 0);
    _put_raw(73, "Settings");
    _put_char(81, 0);
}

int main() {
    init();
    int left, top;
    if (just_starting()) {
      homepagetext();//fill global mem with homepage words
      add_yaml("Homepage.yaml");//call this page
    } else if (received_event()) {
      hubtext();//fill global mem with hub words
      add_yaml("Hub.yaml");
      //keyboardevent(left, top);//function to change keyboard position.
      }
    quit();
}