#include <bits/stdc++.h>

int main(int argc, char* argv[]){
#ifndef BOJ
    freopen(argv[1], "r", stdin);
#endif
    std::cin.tie(NULL);
    std::ios::sync_with_stdio( false );
    std::cout.tie(NULL);

    int N, x;
    std::cin >> N;
    std::vector<int> v(N, 0);
    for(auto &el : v) std::cin >> el;

    std::sort(v.begin(), v.end());

    std::cin >> N;

    while(N--){
        std::cin >> x;
        std::cout << static_cast<bool>(std::distance(std::lower_bound(v.begin(), v.end(), x), std::upper_bound(v.begin(), v.end(), x))) << ' ';
    }
    
    return 0;
}