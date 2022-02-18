#include<vector>
#include<iostream>
int main() {
std::vector<int> v = {2, 3, 5, 7, 11};
for (int i = 0; i < 5; ++i)
std::cerr << v[i] << std::endl;

for (int x : v) //type of values, name of array
    std::cerr << x << std::endl;
std::cerr << v.size() << std::endl;

    v.push_back(22);
    std::cerr << '\n' << v.size() << '\n' << std::endl;
    for (auto x : v)
        std::cerr << x << std::endl;
    
    v.erase(v.begin() + 1);
    for (auto x : v)
        std::cerr << x << std::endl;
    std::cerr << '\n';

    v.insert(v.begin() + 2, 9);
    for (auto x : v)
        std::cerr << x << std::endl;
    std::cerr << '\n';

    v.clear();
    std::cerr << '\n' << v.size() << std::endl;


    v.insert(v.begin(), 9);
    v.insert(v.begin(), 10);
    v.insert(v.begin(), 11);
    v.insert(v.begin() + 1, 12);

    for (auto x : v)
        std::cerr << x << std::endl;
}