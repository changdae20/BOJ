#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    #ifndef BOJ
    freopen("input.txt", "r",stdin);
    #endif

    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;
    std::vector<int> v(N);
    for(auto& n : v) std::cin >> n;
    std::sort(v.begin(),v.end());
    for(auto& n : v) std::cout << n << '\n';
    return 0;
}