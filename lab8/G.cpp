#include<map>//std::map
#include<fstream>
#include<iostream>

//{top_index}
int main() {
std::map<std::string, int> num;//create a number array "num" with number that are named with strings
std::map<std::string, std::string> dict;//create an array called "dict" of strings that are named with strings
std::string fname = "expenses.10000";//create fname for file stream
std::ifstream f(fname.c_str());//
int i = 0;
while (i != 10000) {//while f is reading into varialbe t from data.txt
    //int n;//create int n to hold the number from the column of numbers from data.txt
    //f >> n;//read n from the file
    std::string d;//create d
    getline(f, d);//use getline to read the phrase of the 3rd column of data.txt
    //std::cerr << "term " << t << " num " << n << " definition " << d << std::endl;//output 1 row
    //num[t] = n;//set the string array num's spot t equal to n
//result: the first column's "aardvark" will equal the 2nd column's "438"
    //dict[t] = d;//set the string array dict's spot t equal to d
//result: the first column's "aardvark" will equal the phrase of the 3rd column: "noctural animal"
//not sure if these would work since they are different types
    i++;
    std::cerr << d;
    }
  //std::cerr << num["aardvark"] << ' ' << dict["aardvark"] << std::endl;//2nd and 3rd
//for the first time through "while (f >> t)", output the 2nd and 3rd column since this is what
//num["aardvark"] and dict["aardvark"] were set equal to
  //for (auto p : dict)//flexible type p. output p from string num
    //std::cerr << p.first << ' ' << p.second << std::endl;//p.first and p.second
//access the first and 2nd columns of data.txt. This loop is repeated for all 3 rows
//of data.txt's info.

//my experiment was to change "(auto p : num)" to "(auto p : dict)" and see how the first and 2nd
//columns put out, for num, the first and 2nd column. And, for dict, the first and 3rd column.
}
//1 = 2
//1 = 3
//output 1 and 2
//output 1 and 3

/*
aardvark    438   nocturnal mammal
boardwalk   3892  elevated footpath
cardboard   9283  heavy duty paper product
*/