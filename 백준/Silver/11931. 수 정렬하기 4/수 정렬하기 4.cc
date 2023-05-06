#include <bits/stdc++.h>

int main(){
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int N;
    std::cin >> N;
    std::vector<int> v(N);
    for(auto& el : v) std::cin >> el;
    std::sort(v.begin(), v.end(), std::greater<>());
    for(auto& el : v) std::cout << el << '\n';
    return 0;
}