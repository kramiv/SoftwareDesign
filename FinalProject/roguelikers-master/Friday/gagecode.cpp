//https://docs.google.com/document/d/1TWMzyyjqIvhJYJibgPuAf85RuTrToCqpTUxUf8t2X3E/edit
#include"../../react.h"

//new class idea: types of monsters. make it accelerate or travel in circles.
int k = 0;
class creature{
protected:
    int left;
    int top;
    int health;
    int attack;
    bool dead;
public:
    creature(){
        left = -50;
        top = -50;
    }
    char PrintNumber(int x){
        char c;
        if (x == 0){
            c = '0';
        }
        else if (x == 1){
            c = '1';
        }
        else if (x == 2){
            c = '2';
        }
        else if (x == 3){
            c = '3';
        }
        else if (x == 4){
            c = '4';
        }
        else if (x == 5){
            c = '5';
        }
        else if (x == 6){
            c = '6';
        }
        else if (x == 7){
            c = '7';
        }
        else if (x == 8){
            c = '8';
        }
        else if (x == 9){
            c = '9';
        }
        return c;
    }
    void Setup(int l, int t, int h, int a, bool d){
        left = l;
        top = t;
        health = h;
        attack = a;
        dead = d;
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
    bool CheckDead(){
        return dead;
    }
    void Die(){
        dead = true;
    }
    void Combat(creature &a, creature &b){ //Does damage to health
        b.health = b.health - a.attack; //Problem, this allows enemies to damage enemies. Do I want this to be a thing or no? Could be interesting when it comes to movement. Second problem. If an enemy kills an enemy, somehow the enemy that killed the enemy gets a ton of health (not sure exactly how much). Why does this happen?
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
        a.left = a.left - 10*k;
        if (a.DetectConflict(a,b,c,d,e) == true){
            left = left + 50;
            a.left = a.left + 10*k;
        }
    }

    void MoveRight(creature &a, creature &b, creature &c, creature &d, creature &e) {
        left = left + 50;
        a.left = a.left + 10*k;
        if (a.DetectConflict(a,b,c,d,e) == true){
            left = left - 50;
            a.left = a.left - 10*k;
        }
    }
    void MoveUp(creature &a, creature &b, creature &c, creature &d, creature &e){
        top = top - 50;
        a.top = a.top - 10*k;
        if (a.DetectConflict(a,b,c,d,e) == true){
            top = top + 50;
            a.top = a.top - 10*k;
        }
    }
    void MoveDown(creature &a, creature &b, creature &c, creature &d, creature &e){
        top = top + 50;
        a.top = a.top + 10*k;
        if (a.DetectConflict(a,b,c,d,e) == true){
            top = top - 50;
            a.top = a.top - 10*k;

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
    void PrintGold(int g, int y){
        int x = g%10;
        const char c = PrintNumber(x);
        if (g > 10){
            PrintGold(g/10, y-1);
        }
        _put_char(206+y, c);
    }
    void CheckGold(int g){ //Checks to see what value needs to be sent in to set global mem properly
        int x;
        if (g < 10){
            x = 1;
            PrintGold(g, x-1);
        }
        else if (g > 10 && g < 100){
            x = 2;
            PrintGold(g, x-1);
        }
        else if (g > 100 && g < 1000){
            x = 3;
            PrintGold(g, x-1);
        }
        else if (g > 1000 && g < 10000){
            x = 4;
            PrintGold(g, x-1);
        }
        _put_char(206 + x, '\0');
    }
    int GetGold(){
        return gold;
    }
    void GainGold(creature &a, creature &b, creature &c, creature &d){ //Checks to see if an entity is considered dead and if it is the first round it is considered dead. If it is, pays out 10 gold.
        if (a.Gethealth() <= 0 && a.CheckDead() == false){
            gold = gold + 10;
            a.Die();
        }
        if (b.Gethealth() <= 0 && b.CheckDead() == false){
            gold = gold + 10;
            b.Die();
        }
        if (c.Gethealth() <= 0 && c.CheckDead() == false){
            gold = gold + 10;
            c.Die();
        }
        if (d.Gethealth() <= 0 && d.CheckDead() == false){
            gold = gold + 10;
            d.Die();
        }
    }
    void ReduceGold() {
        gold = gold - 50;
    }
};
void HealthCheker(creature &a, creature &b, creature &c, creature &d, creature &e){
    a.HealthCheck();
    b.HealthCheck();
    c.HealthCheck();
    d.HealthCheck();
    e.HealthCheck();
}
void SetUpRoom(Hero &Player, creature &e1, creature &e2, creature &e3, creature &e4) {//if just starting, it idrectly puts numbers in. Else, it reads from global mem.
    char state;
    /*
    Hero Player;
    creature e1;
    creature e2;
    creature e3;
    creature e4;
    */
    if(just_starting()){ //initializes the player and enemy locations location
        /*
        Player.PSetup(800, 650, 100, 10, 50);
        e1.Setup(600, 300, 10, 5, false);
        e2.Setup(1200, 600, 10, 5, false);
        e3.Setup(1300, 200, 10, 5, false);
        e4.Setup(650, 650, 10, 5, false);
        _put_raw(0, "100/100");
        _put_raw(100, "100/100");
        _put_raw(200, "Gold: ");
        Player.CheckGold(Player.GetGold());
        _put_raw(300, "Menu");
        */
  
    } else {//this information is not in global mem yet.
        Player.PSetup(_get_int(400),_get_int(410),_get_int(500),_get_int(510),_get_int(600));
        e1.Setup(_get_int(420),_get_int(430),_get_int(520),_get_int(530),_get_bool(610));
        e2.Setup(_get_int(440),_get_int(450),_get_int(540),_get_int(550),_get_bool(620));
        e3.Setup(_get_int(460),_get_int(470),_get_int(560),_get_int(570),_get_bool(630));
        e4.Setup(_get_int(480),_get_int(490),_get_int(580),_get_int(590),_get_bool(640));
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
            } else if (event_id_is("return_to_hub")) {
                state = '3';
            }
            e1.EnemyMove(e1, Player, e2, e3, e4);
            e2.EnemyMove(e2, Player, e1, e3, e4);
            e3.EnemyMove(e3, Player, e1, e2, e4);
            e4.EnemyMove(e4, Player, e1, e2, e3);
            HealthCheker(Player, e1, e2, e3, e4);
            Player.GainGold(e1,e2,e3,e4);
            Player.CheckGold(Player.GetGold());
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
    _put_bool(610, e1.CheckDead());
    _put_bool(620, e2.CheckDead());
    _put_bool(630, e3.CheckDead());
    _put_bool(640, e4.CheckDead());
    if (state == '3') {
        add_yaml("Hub.yaml");
    } else {
    add_yaml("gage.yaml", {{"pleft", Player.GetLeft()}, {"ptop", Player.GetTop()},{"e1left", e1.GetLeft()},{"e1top", e1.GetTop()},{"e2left", e2.GetLeft()},{"e2top", e2.GetTop()},{"e3left", e3.GetLeft()},{"e3top", e3.GetTop()},{"e4left", e4.GetLeft()},{"e4top", e4.GetTop()}});
    }
}

//modify global mem

void homepagetext() {
    _put_raw(1700, "Roguelikers");
    _put_char(1711, 0);
    //_put_raw(712, "Select New Run");
    //_put_char(726, 0);
    _put_raw(1727, "Select New Run");
    _put_char(1741, 0);
    _put_raw(1755, "Run 1");
    _put_char(1760, 0);
    _put_raw(1761, "Run 2");
    _put_char(1766, 0);
    _put_raw(1767, "Run 3");
    _put_char(1772, 0);
    _put_raw(1773, "Settings");
    _put_char(1781, 0);
}

void hubtext() {
    _put_raw(1700, "Upgrades Shop");
    _put_char(1714 , 0);
    _put_raw(1715, "Clothing Shop");
    _put_char(1728, 0);
    _put_raw(1729, "Dungeon Entrance");
    _put_char(1745, 0);
}

void Roguelikerstext() {
  _put_raw(1700, "Roguelikers");
  _put_char(1711, 0);
  _put_raw(1712, "Proceed");
  _put_char(1719, 0);
}

int main() {
  Hero Player;//these obs are different from the ones in setuproom.
  creature e1;//these are used to just imitate the objs to put stuff
  creature e2;//into global mem more easily. Then the 'real' objs
  creature e3;//pull those values from global mem in setuproom().
  creature e4;//I could put these in as references, but it already
//reinitializes the content of those objects from global mem. I could use them
//as references though.
  init();
  char state;//set "state" = '5' to save time when testing.
  if (just_starting()) {//app is starting, not a webpage.
    std::cerr << "under just_starting()" << std::endl;
    state = '1';
    _put_char(1800, state);  // record the starting state
    Roguelikerstext();
    add_yaml("Roguelikers.yaml");
    add_yaml("singleKey.yaml");  // listen for a single keypress
    Player.PSetup(800, 650, 100, 10, 50);
    e1.Setup(600, 300, 10, 5, false);
    e2.Setup(1200, 600, 10, 5, false);
    e3.Setup(1300, 200, 10, 5, false);
    e4.Setup(650, 650, 10, 5, false);
    _put_raw(0, "100/100");
    _put_raw(100, "100/100");
    _put_raw(200, "Gold: ");
    Player.CheckGold(Player.GetGold());
    _put_raw(300, "Menu");
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
    _put_bool(610, e1.CheckDead());
    _put_bool(620, e2.CheckDead());
    _put_bool(630, e3.CheckDead());
    _put_bool(640, e4.CheckDead());
  } else {
    if (received_event()) {
      state = _get_char(1800);
      if ('1' == state) {  // just got the starting keypres
        homepagetext();//fill global mem with homepage words
        add_yaml("Homepage.yaml");
        std::cerr << "under if '1' == state";
        state = '2';
        _put_char(1800, state);  // waiting for a textInput event
      } else {
        if ('2' == state) {  // received textInput event
          state = '3';
          std::cerr << "under if '2' == state ";
          std::cerr << "move circle" << std::endl;
          _put_char(1800, state); // waiting for keyboard event
          
        } else if ('3' == state) {
          std::cerr << "under if '3' == state" << std::endl;

          if (event_id_is("dungeon_entrance")) {
            std::cerr << "open dungeon";
            state = '5';
            _put_char(1800, state); // waiting for keyboard event
          } else if (event_id_is("upgrades_shop")) {
            state = '6';
            _put_char(1800, state); // waiting for keyboard event
          } else if (event_id_is("purchase_speed")) {
            if (Player.GetGold() >=50) {
                Player.ReduceGold();
                k++;
              }
              std::cerr << "speed increased";
          } else if (event_id_is("return_to_hub")) {
                state = '3';
                _put_char(1800, state); // waiting for keyboard event
            }
        }
        
        if ('3' == state) {
          hubtext();//fill global mem with hub words
          add_yaml("Hub.yaml");
        }
        if ('4' == state) {//open shop function with yaml and modify character's health, etc.
          std::cerr << "clothing shop yaml";
          state = '3';
        }
        if ('5' == state) {
//I need just_starting to work here too. SetUpRoom doesn't realize
//that it needs to start now. just_starting is false. 
          SetUpRoom(Player, e1, e2, e3, e4);//change state from inside of this fucntion
          //using state variable.
//change state != '5'. change it to '3'.
        }
        if ('6' == state) {
          add_yaml("upgrades_shop.yaml");
        }

//it always adds these.
        //add_yaml("singleKey.yaml");  // listen for a single keypress
        //add_yaml("circle.yaml", {{"left", left}, {"top", top}});
      }
    }



  }//end of "else"
  quit();
}


/*
 else if (event_id_is("select_previously_saved_run")) {
            state = '4';
            _put_char(100, state);
            */

/*
5 classes
understanding of classes.
create more functions
(simplify my opening yaml pages to work on classes)
work on creating code that emphasizes .cpp code (more functionality)
*/
