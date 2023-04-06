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

    std::vector<int> v(n);
    for(int i=0; i<n; ++i){
        std::cin >> v[i];
    }

    for(auto& num : v){
        if(num<s){
            std::cout << num << ' ';
        }
    }
}