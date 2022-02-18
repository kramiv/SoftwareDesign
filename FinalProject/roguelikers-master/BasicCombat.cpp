#include "../react.h"

class creature{
protected:
    int left;
    int top;
    int health;
    int attack;
public:
    creature(){
        left = -50;
        top = -50;
    }
    void Setup(int l, int t, int h, int a){
        left = l;
        top = t;
        health = h;
        attack = a;
    }
    int GetLeft(){
        return left;
    }
    int GetTop(){
        return top;
    }
    int Gethealth(){
        return health;
    }
    int Getattack(){
        return attack;
    }
    void Combat(creature &a, creature &b){ //Does damage to health
        b.health = b.health - a.attack; //Problem, this allows enemies to damage enemies. Do I want this to be a thing or no? Could be interesting when it comes to movement.
    }
    void HealthCheck(){ //If the entity is dead, it is moved off of the screen
        if (health == 0){
            left = -1000;
            top = -1000;
        }
    }
    bool DetectConflict(creature &a, creature &b, creature &c, creature &d, creature &e){ //Detects conflicting movement and initiates combat if moving into a shared tile
        if(a.GetLeft() > 1650 || a.GetLeft() < 0 || a.GetTop() < 0 || a.GetTop() > 650){
            return true;
        }
        else if(a.GetLeft() == b.GetLeft() && a.GetTop() == b.GetTop()){
            a.Combat(a,b);
            return true;
        }
        else if(a.GetLeft() == c.GetLeft() && a.GetTop() == c.GetTop()){
            a.Combat(a,c);
            return true;
        }
        else if(a.GetLeft() == d.GetLeft() && a.GetTop() == d.GetTop()){
            a.Combat(a,d);
            return true;
        }
        else if(a.GetLeft() == e.GetLeft() && a.GetTop() == e.GetTop()){
            a.Combat(a,e);
            return true;
        }
        else{
            return false;
        }
    }
    void EnemyMove(creature &a, creature &b, creature &c, creature &d, creature &e){
        if (a.GetLeft() > b.GetLeft()){
            left = left - 50;
            if (a.DetectConflict(a,b,c,d,e) == true){
                left = left + 50;
            }
        }
        else if (a.GetLeft() < b.GetLeft()){
            left = left + 50;
            if (a.DetectConflict(a,b,c,d,e) == true){
                left = left - 50;
            }
        }
        else if (a.GetTop() > b.GetTop()){
            top = top - 50;
            if (a.DetectConflict(a,b,c,d,e) == true){
                top = top + 50;
            }
        }
        else if (a.GetTop() < b.GetTop()){
            top = top + 50;
            if (a.DetectConflict(a,b,c,d,e) == true){
                top = top - 50;
            }
        }
    }
    void MoveLeft(creature &a, creature &b, creature &c, creature &d, creature &e){
        left = left - 50;
        if (a.DetectConflict(a,b,c,d,e) == true){
            left = left + 50;
        }
    }
    void MoveRight(creature &a, creature &b, creature &c, creature &d, creature &e){
        left = left + 50;
        if (a.DetectConflict(a,b,c,d,e) == true){
            left = left - 50;
        }
    }
    void MoveUp(creature &a, creature &b, creature &c, creature &d, creature &e){
        top = top - 50;
        if (a.DetectConflict(a,b,c,d,e) == true){
            top = top + 50;
        }
    }
    void MoveDown(creature &a, creature &b, creature &c, creature &d, creature &e){
        top = top + 50;
        if (a.DetectConflict(a,b,c,d,e) == true){
            top = top - 50;
        }
    }
};
class Hero: public creature{  //Subclass for hero specific variables and functions
    int gold;
public:
    void PSetup(int l, int t, int h, int a, int g){
        left = l;
        top = t;
        health = h;
        attack = a;
        gold = g;
    }
    int GetGold(){
        return gold;
    }
    void GainGold(){
        gold = gold + 10;
    }
};
void HealthCheker(creature &a, creature &b, creature &c, creature &d, creature &e){
    a.HealthCheck();
    b.HealthCheck();
    c.HealthCheck();
    d.HealthCheck();
    e.HealthCheck();
}
void SetUpRoom(){
    Hero Player;
    creature e1;
    creature e2;
    creature e3;
    creature e4;
    if(just_starting()){ //initializes the player and enemy locations location
        Player.PSetup(800, 650, 100, 10, 50);
        e1.Setup(600, 300, 10, 5);
        e2.Setup(1200, 600, 10, 5);
        e3.Setup(1300, 200, 10, 5);
        e4.Setup(650, 650, 10, 5);
        _put_raw(0, "100/100");
        _put_raw(100, "100/100");
        _put_raw(200, "Gold: ");
        _put_raw(206, "50");
        _put_raw(300, "Menu");
    }
    else{
        Player.PSetup(_get_int(400),_get_int(410),_get_int(500),_get_int(510),_get_int(600));
        e1.Setup(_get_int(420),_get_int(430),_get_int(520),_get_int(530));
        e2.Setup(_get_int(440),_get_int(450),_get_int(540),_get_int(550));
        e3.Setup(_get_int(460),_get_int(470),_get_int(560),_get_int(570));
        e4.Setup(_get_int(480),_get_int(490),_get_int(580),_get_int(590));
        if (received_event()){ //Checks for user input
            if (event_id_is("KeyArrowLeft")){
                Player.MoveLeft(Player, e1, e2, e3, e4);
            }
            else if (event_id_is("KeyArrowRight")){
                Player.MoveRight(Player, e1, e2, e3, e4);
            }
            else if (event_id_is("KeyArrowUp")){
                Player.MoveUp(Player, e1, e2, e3, e4);
            }
            else if (event_id_is("KeyArrowDown")){
                Player.MoveDown(Player, e1, e2, e3, e4);
            }
            e1.EnemyMove(e1, Player, e2, e3, e4);
            e2.EnemyMove(e2, Player, e1, e3, e4);
            e3.EnemyMove(e3, Player, e1, e2, e4);
            e4.EnemyMove(e4, Player, e1, e2, e3);
            HealthCheker(Player, e1, e2, e3, e4);
        }
    }
    _put_int(400, Player.GetLeft());
    _put_int(410, Player.GetTop());
    _put_int(420, e1.GetLeft());
    _put_int(430, e1.GetTop());
    _put_int(440, e2.GetLeft());
    _put_int(450, e2.GetTop());
    _put_int(460, e3.GetLeft());
    _put_int(470, e3.GetTop());
    _put_int(480, e4.GetLeft());
    _put_int(490, e4.GetTop());
    _put_int(500, Player.Gethealth());
    _put_int(510, Player.Getattack());
    _put_int(520, e1.Gethealth());
    _put_int(530, e1.Getattack());
    _put_int(540, e2.Gethealth());
    _put_int(550, e2.Getattack());
    _put_int(560, e3.Gethealth());
    _put_int(570, e3.Getattack());
    _put_int(580, e4.Gethealth());
    _put_int(590, e4.Getattack());
    _put_int(600, Player.GetGold());
    add_yaml("testing2.yaml", {{"pleft", Player.GetLeft()}, {"ptop", Player.GetTop()},{"e1left", e1.GetLeft()},{"e1top", e1.GetTop()},{"e2left", e2.GetLeft()},{"e2top", e2.GetTop()},{"e3left", e3.GetLeft()},{"e3top", e3.GetTop()},{"e4left", e4.GetLeft()},{"e4top", e4.GetTop()}});
}

int main(){
    init();
    SetUpRoom();
    quit();
}