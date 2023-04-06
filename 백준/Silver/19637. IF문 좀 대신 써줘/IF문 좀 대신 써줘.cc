#include <bits/stdc++.h>

int main( int argc, char *argv[] ) {
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif
    std::cin.tie( NULL );
    std::ios::sync_with_stdio( false );
    std::cout.tie( NULL );

    int N,M;

    std::cin >> N >> M;

    std::vector<std::pair<std::string, int>> badges(N);

    for(auto& [badge, value] : badges){
        std::cin >> badge >> value;
    }

    int q;
    while(M--){
        std::cin >> q;
        auto it = std::lower_bound(badges.begin(), badges.end(), q, [](auto& a, auto& b){
            return a.second < b; 
        });
        std::cout << it->first << '\n';
    }

    return 0;
}