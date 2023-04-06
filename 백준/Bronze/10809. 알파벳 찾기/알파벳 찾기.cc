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

    std::string s;
    std::cin >> s;

    for(char c = 'a'; c <= 'z'; ++c){
        auto it = std::find(s.begin(), s.end(), c);
        if(it == s.end()){
            std::cout << -1 << ' ';
        }else{
            std::cout << std::distance(s.begin(), it) << ' ';
        }
    }
}