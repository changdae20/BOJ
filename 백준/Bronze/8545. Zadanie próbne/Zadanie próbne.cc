#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>

int main(){
    #ifndef BOJ
    freopen("input.txt", "r", stdin);
    #endif

    std::string a;
    std::cin >> a;
    std::cout << std::string(a.rbegin(), a.rend()) << std::endl;
}