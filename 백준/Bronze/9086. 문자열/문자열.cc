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
        std::cout << *s.begin() << *(s.end()-1) << std::endl;
    }
}