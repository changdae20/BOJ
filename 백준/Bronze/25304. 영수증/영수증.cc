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

    int total;
    int n;

    std::cin >> total >> n;

    std::vector<int> a(n);
    std::vector<int> b(n);

    for(int i = 0; i < n; ++i){
        std::cin >> a[i] >> b[i];
    }

    std::cout << (std::inner_product(a.begin(), a.end(), b.begin(), 0)==total ? "Yes" : "No") << std::endl;
}