#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio( false );std::cin.tie( NULL );std::cout.tie( NULL );

int main( int argc, char *argv[] ) {
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif
    fastio;

    int N;
    std::cin >> N;
    std::vector<int> v(N);
    for(auto& el : v) std::cin >> el;
    std::sort(v.begin(), v.end(), std::greater<>());
    std::cout << std::accumulate(v.begin(), v.end(), 0, [n=0](int s, int el) mutable{return s + el * (++n);}) << std::endl;
    
    return 0;
}