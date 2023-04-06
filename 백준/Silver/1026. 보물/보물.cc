#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio( false );std::cin.tie( NULL );std::cout.tie( NULL );

int main( int argc, char *argv[] ) {
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif
    fastio;

    int N;
    std::cin >> N;
    std::vector<int> v1(N);
    std::vector<int> v2(N);
    for(auto& el : v1) std::cin >> el;
    for(auto& el : v2) std::cin >> el;
    std::sort(v1.begin(), v1.end(), std::greater<>());
    std::sort(v2.begin(), v2.end());
    std::cout << std::inner_product(v1.begin(), v1.end(), v2.begin(), 0) << std::endl;
    
    return 0;
}