//left off "We still have some remnants of testing our handle_button function ob...""
//p. 12

#include"../react.h"

void make_button(int i, unsigned char *array) {
    int r = array[3*i + 0];
    int g = array[3*i + 1];
    int b = array[3*i + 2];
    int r2 = array[3*(i) + 0] + 50;
    int g2 = array[3*(i) + 1] + 50;
    int b2 = array[3*(i) + 2] + 50;
    add_yaml("button.yaml", {{"id", i}, {"r", r}, {"g", g}, {"b", b}, {"r2", r2}, {"g2", g2}, {"b2", b2}});
}

void handle_button(int button) {
    std::cerr << "value of button: " << (button + 1) << '\n';
//to do with ascii. 123 124 125 126 taken.
//swapping used
//ascii = 1 character per byte. no swapping needed
//int and ascii characters no ccoupy same place in global meme
/*
        if (num_moves == 1) {
            _put_raw(129, " move.");
            int tensDigit = num_moves/10;
            int onesDigit = num_moves%10;
            char tensDigitChar = '0' + tensDigit;
            char onesDigitChar = '0' + onesDigit;
            _put_char(127, tensDigitChar);
            _put_char(128, onesDigitChar);
            //_put_char(140, 0);
        } else {
            _put_raw(129, " moves.");
            int tensDigit = num_moves/10;
            int onesDigit = num_moves%10;
            char tensDigitChar = '0' + tensDigit;
            char onesDigitChar = '0' + onesDigit;
            _put_char(127, tensDigitChar);
            _put_char(128, onesDigitChar);
            //_put_char(140, 0);
        }

        _put_raw(127, "num moves: ");
        int tensDigit = num_moves/10;
        int onesDigit = num_moves%10;
        char tensDigitChar = '0' + tensDigit;
        char onesDigitChar = '0' + onesDigit;
        //this goes up to 99
        _put_char(138, tensDigitChar);
        _put_char(139, onesDigitChar);
        _put_char(140, 0);
        */
        //add_yaml("flood_fill.yaml", {{"top_index", 127}});
        //add_yaml("flood_fill.yaml", {{"top_index", 150}});
        //_put_raw(50, "2nd message at index 150");
        
}

int main() {
    int num_moves;
    const int num_colors = 6;
    init();
    if (just_starting()) {
    int num_moves = 0;
    _put_int(123, num_moves);
    add_yaml("flood_fill.yaml", {{"top_index", 50}});    
    _put_raw(50, "0 moves.");
    unsigned char button_colors[18] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170};
    for (int i = 0; i < num_colors; i++) {
        make_button(i, button_colors);
        }
    } else if (received_event()) {
    num_moves = _get_int(123);

    //add_yaml("flood_fill.yaml", {{"top_index", 150}});
    //_put_raw(50, "2nd message at index 150");
    unsigned char button_colors[18] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170};
    add_yaml("flood_fill.yaml", {{"top_index", 127}});
    for (int i = 0; i < num_colors; i++) {
    make_button(i, button_colors);
    }
//yaml info and global mem are sent separately: order of yamls matters
//but not relative to C++ functions that create them
    for (int i = 0; i < num_colors; i++) {
    if (event_id_is("button_", i)) {
        handle_button(i);//num_moves
        _put_int(123, num_moves);//stored in 4 bytes without anythig
        _put_raw(127, "num moves: ");
        int tensDigit = num_moves/10;
        int onesDigit = num_moves%10;
        char tensDigitChar = '0' + tensDigit;
        char onesDigitChar = '0' + onesDigit;
        //this goes up to 99
        _put_char(138, tensDigitChar);
        _put_char(139, onesDigitChar);
        _put_char(140, 0);
        add_yaml("flood_fill.yaml", {{"top_index", 127}});

        num_moves++;
        }
        //add_yaml("flood_fill.yaml", {{"top_index", 150}});
        //_put_raw(50, "2nd message at index 150");
    }
    }
    quit();
}


/*
convert int into ascii: num_moves is 2-digit in base 10
int tensDigit = num_moves/10;
int onesDigit = num_moves%10;
char tensDigitChar = '0' + tensDigit;
char onesDigitChar = '0' + onesDigit;
_put_char(123, tensDigitChar);
_put_char(123, onesDigitChar);

*/




/*
client: runs inside of the web browser. whenever the user does something, then
a message is sent via a bride from the client to the server.
bridge runs the server program from the start.
processes the input and sends back a respones right away.


if I want text to show up in the browser - knowing that yaml is sent too - 
I have to look for characters starting at this index of global mem

*/