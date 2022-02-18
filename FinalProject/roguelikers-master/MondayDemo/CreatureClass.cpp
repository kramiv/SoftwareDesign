#include "../react.h"

class creature{
    int left;
    int top;
public:
    creature(){
        left = -50;
        top = -50;
    }
    void Setup(int l, int t){
        left = l;
        top = t;
    }
    int GetLeft(){
        return left;
    }
    int GetTop(){
        return top;
    }
    bool DetectConflict(creature &a, creature &b, creature &c, creature &d, creature &e){
        if(a.GetLeft() > 1650 || a.GetLeft() < 0 || a.GetTop() < 0 || a.GetTop() > 650){
            return true;
        }
        else if(a.GetLeft() == b.GetLeft() && a.GetTop() == b.GetTop()){
            return true;
        }
        else if(a.GetLeft() == c.GetLeft() && a.GetTop() == c.GetTop()){
            return true;
        }
        else if(a.GetLeft() == d.GetLeft() && a.GetTop() == d.GetTop()){
            return true;
        }
        else if(a.GetLeft() == e.GetLeft() && a.GetTop() == e.GetTop()){
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

void SetUpRoom(){
    creature Player;
    creature e1;
    creature e2;
    creature e3;
    creature e4;
    if(just_starting()){ //initializes the player and enemy locations location
        Player.Setup(800, 650);
        e1.Setup(600, 300);
        e2.Setup(1200, 600);
        e3.Setup(1300, 200);
        e4.Setup(650, 650);
        _put_raw(0, "100/100");
        _put_raw(100, "100/100");
        _put_raw(200, "Gold: 50");
        _put_raw(300, "Menu");
    }
    else{
        Player.Setup(_get_int(400),_get_int(410));
        e1.Setup(_get_int(420),_get_int(430));
        e2.Setup(_get_int(440),_get_int(450));
        e3.Setup(_get_int(460),_get_int(470));
        e4.Setup(_get_int(480),_get_int(490));
        if (received_event()){ //Checks for user input
            if (event_id_is("KeyArrowLeft")){
                Player.MoveLeft(Player, e1, e2, e3, e4);
                e1.EnemyMove(e1, Player, e2, e3, e4);
                e2.EnemyMove(e2, Player, e1, e3, e4);
                e3.EnemyMove(e3, Player, e1, e2, e4);
                e4.EnemyMove(e4, Player, e1, e2, e3);
            }
            else if (event_id_is("KeyArrowRight")){
                Player.MoveRight(Player, e1, e2, e3, e4);
                e1.EnemyMove(e1, Player, e2, e3, e4);
                e2.EnemyMove(e2, Player, e1, e3, e4);
                e3.EnemyMove(e3, Player, e1, e2, e4);
                e4.EnemyMove(e4, Player, e1, e2, e3);
            }
            else if (event_id_is("KeyArrowUp")){
                Player.MoveUp(Player, e1, e2, e3, e4);
                e1.EnemyMove(e1, Player, e2, e3, e4);
                e2.EnemyMove(e2, Player, e1, e3, e4);
                e3.EnemyMove(e3, Player, e1, e2, e4);
                e4.EnemyMove(e4, Player, e1, e2, e3);
            }
            else if (event_id_is("KeyArrowDown")){
                Player.MoveDown(Player, e1, e2, e3, e4);
                e1.EnemyMove(e1, Player, e2, e3, e4);
                e2.EnemyMove(e2, Player, e1, e3, e4);
                e3.EnemyMove(e3, Player, e1, e2, e4);
                e4.EnemyMove(e4, Player, e1, e2, e3);
            }
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
    add_yaml("testing2.yaml", {{"pleft", Player.GetLeft()}, {"ptop", Player.GetTop()},{"e1left", e1.GetLeft()},{"e1top", e1.GetTop()},{"e2left", e2.GetLeft()},{"e2top", e2.GetTop()},{"e3left", e3.GetLeft()},{"e3top", e3.GetTop()},{"e4left", e4.GetLeft()},{"e4top", e4.GetTop()}});
}

int main(){
    init();
    SetUpRoom();
    quit();
}