//create class without a constructor
//constructor = function like init() that changes
//the data membesr.
//class should have 2 member variables
//does not need member fucntion besides init()

struct Donut {
    float flavor, shape;
    void init(float x, float y) {
        flavor = x;
        shape = y;
    }

int main() {
    Donut a, b;
    a.init(1,2);
    b.init(3,4);
}