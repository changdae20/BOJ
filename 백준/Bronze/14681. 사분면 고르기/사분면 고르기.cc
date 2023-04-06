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

    int n,s;

    std::cin >> n >> s;

    if(n>0&&s>0) std::cout << '1';
    else if(n<0&&s>0) std::cout << '2';
    else if(n<0&&s<0) std::cout << '3';
    else if(n>0&&s<0) std::cout << '4';
}