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

    std::vector<int> v(n);
    for(int i=0; i<n; ++i){
        std::cin >> v[i];
    }

    int q;
    std::cin >> q;
    std::cout << std::count(v.begin(), v.end(), q) << std::endl;
}