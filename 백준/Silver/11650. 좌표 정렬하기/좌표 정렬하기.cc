#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio( false );std::cin.tie( NULL );std::cout.tie( NULL );

int main( int argc, char *argv[] ) {
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif
    fastio;

    int N;
    std::cin >> N;
    std::vector<std::pair<int,int>> v(N);
    for(auto& el : v) std::cin >> el.first >> el.second;
    std::sort(v.begin(), v.end(), [](auto& p1, auto& p2){
        if(p1.first==p2.first) return p1.second<p2.second;
        else return p1.first<p2.first;
    });
    for(auto& el : v) std::cout << el.first << ' ' << el.second << '\n';
    
    return 0;
}