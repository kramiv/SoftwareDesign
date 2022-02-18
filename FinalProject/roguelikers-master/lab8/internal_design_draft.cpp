

/*
Olaf wants us to communicate in words how we will do this and decide what kinds 
of fucntional we need.
First off, we need to build a dungeon page.
1. create a yaml for the dungeon page
2. create "Hero" with a health status bar and continuous mouse usage. Find a way to
make the Hero move around using the mouse or the arrow keys. 
3. find a way to track the Hero's position (Ivana)
4. create enemies - stationary for now. They are buttons that lower the health bar
if the Hero hovers over them
5. Calculate the position of the Hero and the distance between Hero and enemy. If
within a certain radius, inflict damage. (Ivana)
That will be good for now.



For now, what I'm going to try to do is to set up a web browser with a basic 
homepage and then create some buttons on it. I want to see if I can change the 
positions of the buttons from the .cpp file.
*/






#include"../react.h"
//#include<map>//std::map
#include<iostream>
//this is missing a lot of the 'details'. Goal = overall structure.
//when do I create different .cpp files and use .h with it?
//how do I put teh game on an x-y plane? Would make updating positions easier.
//okay I am done for now.
//hm. .h is good for creating subclasses or classes on top of a class.
char state;
 
int autoPosX(int x) {
    //I need to randomly generate the next x coordinate
    //x = x - 3;
    //add boudns so it doesn't go offscreen.
}
 
int autoPosY(int y) {
    //I need to randomly generate the next y coordinate
    //y = y + 1;
    //add bounds so it doesn't go offscreen;
}
 
 
int getPosx() {
    //some sort of fucntion to get the user's current position in x plane
    //return x;
    //need a way to use mouse or arrow functionality as an event
    //maybe check for it continuously with true = event();    while (event()) {update pos using reference}
}
 
int getPosy() {
    //some sort of function to get teh user's current position in y plane
    //return y;
    //need a way to use mouse or arrow functionality as an event
}
 
class Character {
    int x;
    int y;
    int health;//need to find a way to display this out of 100 using yaml
//basically to find a way to use a number from a .cpp file to modify reactview display through yaml.
    int damage_taken;
    int damage;
    Position() {
        x = getPosx();
        y = getPosy();
    }
    UpdatePos() {
        x = getPosx();
        y = getPosy();
    }
    attack() {
        //throw an attack 
        //on a continuous interval during run-time, throw out damage on an x-y plane
        //I also need a function that will create the ball of damage in the yaml so the user can see it
    }
    take_damage() {
        //if (received_event) {}
        //  health = health - 5;
    }
};//this needs to be called whenever there is a new movement event. Not sure how to do this.
 
 
class Enemy : Character {
    int attack_interval;
    int posx;
    int posy;
public:
    Enemy() {
        int = 5;
    }
    send_attack() {
        //need to find a way to send an attack at 1. a random angle and 2. until it hits a wall
        //using x-y plane.
        //or add soem kind of probability component to it:
        //if the character makes a move, then the enemy has a 20% chance of changing character's health
        //how could I arrange the classes like this or call them like this?
    }
    UpdatePos() {
        posx = autoPosX();
        posy = autoPosY();
    }
};//how do I create individual enemies that refer to a specific yaml to look all look the same?
//I'd use a link to a gif to do this.
 
 
class Hero : Character {
    int posx;
    int posy;
 //   int health;
    //need a way to 1. get hero's position
    //and 2. use user's actions to modify the position:
    Hero() {
 
    }
    UpdatePos() {
        x = getPosx();
        y = getPosy();
    }
};
 
 
class Map{
    char* id;
public:
    Map() {
        for (int i = 0; i < 5; i++) {
            id[i] = '\0';//make it equal to nothing
        }
    }
    Map_Fill(char a) {
        if (id[0] == 0) {
            id[0] = a;
        } else if (id[1] == 0) {
            id[1] = a;
        } else if (id[2] == 0) {
            id[2] = a;
        } else if (id[3] == 0) {
            id[3] = a;
        } else if (id[4] == 0) {
            id[4] = a;
        }
    }
    Map_yaml() {//how to return this to use in main so I can put text in yaml?
        std::cerr << id;
    }
};
 
void Dungeon() {
    char rooms[5] = {'e', 'f', 'g', 'h', 'i'};
    //randomly select char[1-5];
    state = rooms[0];//construct a dungeon:
    Map m1(rooms[1]);//plug in 'e' to add it to the map obj
}
 
 
int main() {
    init(); // receives message + stores in a file from browser
    state = _get_char(2);
    _put_raw(5, "abcde");
    if (just_starting()) {
        state = 'a'; // this is the very first page that introduces the game's name and "proceed" button
        _put_char(2, state);
    } else if (received_event()) {
        if (event_id_is("new_gamerun")) {
            state = 'b';
            _put_char(2, state);
    } else if (event_id_is("home")) {
        //std::cerr << "ok!";
        state = 'c';
        _put_char(2, state);
    } else if (event_id_is("dungeon_loading_page")) {
        state = 'd';
        _put_char(2, state);
    }
 
    if ('a' == state) add_yaml("firstpage.yaml");
    if ('b' == state) add_yaml("new_gamerun.yaml");
    if ('c' == state), add_yaml("home.yaml");
    if ('d' == state), add_yaml("dungeon_loading_page.yaml") : Dungeon(); // does this work
    if ('e' == state), add_yaml("dungeon_pageE.yaml");
    if ('f' == state), add_yaml("dungeon_pageF.yaml");
    if ('g' == state), add_yaml("dungeon_pageG.yaml");
    if ('h' == state), add_yaml("dungeon_pageH.yaml");
    if ('i' == state), add_yaml("dungeon_pageI.yaml");
  quit();//quit sends information back to bridge.py to client
}
