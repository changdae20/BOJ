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

    std::vector<int> v;
    int n;

    for(int i=0;i<28;i++){
        std::cin >> n;
        v.push_back(n);
    }

    std::sort(v.begin(), v.end());
    std::cout << std::distance(v.begin(), std::find_if(v.begin(), v.end(), [m=1](int n) mutable { return n != m++; }))+1 << std::endl;
    std::cout << 30-std::distance(v.rbegin(), std::find_if(v.rbegin(), v.rend(), [m=30](int n) mutable { return n != m--; })) << std::endl;
}