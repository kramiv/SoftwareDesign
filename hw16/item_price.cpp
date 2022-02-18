
#include<iostream>
int item_count;
double *item_price;

void print_items() {
  for (int i = 0; i < item_count; ++i) {
    std::cerr << item_price[i] << ' ';
  }
}

void change_items() {
  delete [] item_price;
  item_count = 3;
  item_price = new double[item_count];
  item_price[0] = 9;
  item_price[1] = 11;
  item_price[2] = 13;
}

void double_length () {
    double *temp;//say length "x"
    temp = new double[item_count*2];
    for (int i = 0; i < item_count; i++) {
        temp[i] = item_price[i];
    }//now, double:
    for (int i = 0; i < item_count; i++) {
        temp[item_count + i] = item_price[i];
    }//now, clear original array and make new array
    delete [] item_price;
    item_price = new double[2*item_count];
    for (int i = 0; i < item_count*2; i++) {
        item_price[i] = temp[i];
    }
}

int main() {
  item_count = 2;
  item_price = new double[item_count];
  item_price[0] = 5;
  item_price[1] = 7;
  //print_items();
  change_items();
  print_items();
  double_length();
  print_items();
  delete [] item_price;
}
