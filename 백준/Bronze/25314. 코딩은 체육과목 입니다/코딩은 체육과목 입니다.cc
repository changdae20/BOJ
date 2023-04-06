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
    for(int i=0; i<(n/4);i++){
        std::cout << "long ";
    }
    std::cout << "int";
}