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
    std::cout << (((n * (100-s))>=10000) ? '0' : '1');
}