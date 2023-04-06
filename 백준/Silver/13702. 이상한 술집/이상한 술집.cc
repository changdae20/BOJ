#include <bits/stdc++.h>

int main( int argc, char *argv[] ) {
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif
    std::cin.tie( NULL );
    std::ios::sync_with_stdio( false );
    std::cout.tie( NULL );

    unsigned long long N, K;

    std::cin >> N >> K;

    std::vector<unsigned long long> zoozunza(N);

    for(auto& el : zoozunza) std::cin >> el;

    unsigned long long l = 0;
    unsigned long long r = 2147483648uLL;

    while(l+1 < r){
        auto mid = (l+r)/2uLL;
        if(std::accumulate(zoozunza.begin(), zoozunza.end(), 0uLL, [&mid](int acc, int z){
            return acc + z/mid;
        }) >= K) l = mid;
        else r = mid;
    }

    std::cout << l << '\n';
    
    return 0;
}