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

    int n;
    std::cin >> n;

    std::string s;
    while(n--){
        std::cin >> s;
        std::cout << ((s.length()>=6 && s.length()<=9) ? "yes" : "no") << std::endl;
    }
}