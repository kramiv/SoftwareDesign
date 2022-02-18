//move square and keep track of position.
//one enemy, one hero.
//create two circles views. position them with an index.
//calculate radius or at least enter it
//separate colors
//set bounds for what the position is set equal to. 
//need to experiment with that though
//to add later: random intervals of attack that will use an "attack.yaml".
//if position of these is in a certain range of enemy, inflict damage.
//oh huh. compilation rules. g++ -Wall grid.cpp ../react.o -lcurl work?
#include"../react.h"

//plug in functions for modifying positions, see % would work
//I'm assuming that since Gage didn't respond, we have a functioning
//version and yamls

int main() {
    int leftH;//global mem 10
    int topH;//global mem 20
    int leftE;//global mem 30
    int topE;//global mem 40
    init();
    if (just_starting()) {
        int leftH = 20%;//global mem 10
        _put_int(10, 20%);
        int topH = 20%;//global mem 20
        _put_int(20, 20%);
        int leftE = 40%;//global mem 30
        _put_int(30, 40%);
        int topE = 40%;//global mem 40
        _put_int(40, 40%);
        add_yaml("EnemyHero.yaml", {{"radiusHero", 25}, {"leftHero", leftH}, {"topHero", topH}, {"radiusEnemy", 40}, {"leftEnemy", leftE}, {"topEnemy", topE}});
        } else if (received_event()){
            leftH = _get_int(10);
            topH = _get_int(20);
            leftE = _get_int(30);
            topE = _get_int(40);
            add_yaml("EnemyHero.yaml", {{"radiusHero", 25}, {"leftHero", leftH}, {"topHero", topH}, {"radiusEnemy", 40}, {"leftEnemy", leftE}, {"topEnemy", topE}});
            
    }
    quit();
}
