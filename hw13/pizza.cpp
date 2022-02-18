#include <iostream>
//finish show_change()
struct Town {
    double total_pizza;
    int num_inhabitants;
    double per_capita() {
        double res = total_pizza/num_inhabitants;
        return res;
  }
    int num_students;
    int rate;
    double pizza_for_students() {
        double res1 = num_students*rate;
        return res1;
    }
    double tenpermore() {
        double res2 = (res1)*(1.1);
        return res2;
    }
    double show_change() {//finish
        pizza_for_students();
        std::cerr << pizza_for_students() << " ";
        tenpermore();
        std::cerr << tenpermore();


    }
};

int main() {
    Town northfield {500000.1, 20007, 8000, 25};
    Town faribault {400000, 23750, 1000, 17};
    northfield.per_capita();
    faribault.per_capita();
    northfield.pizza_for_students();
    faribault.pizza_for_students();
    northfield.tenpermore();
    faribault.tenpermore();
    std::cerr << northfield.per_capita() << " "<< northfield.pizza_for_students() << " " << northfield.tenpermore();
    std::cerr << faribault.per_capita() << " "<< faribault.pizza_for_students() << " " << faribault.tenpermore();
}