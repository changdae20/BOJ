#include <bits/stdc++.h>

int main( int argc, char *argv[] ) {
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif
    std::cin.tie( NULL );
    std::ios::sync_with_stdio( false );
    std::cout.tie( NULL );

    unsigned long long N, L, W, H;

    std::cin >> N >> L >> W >> H;

    long double l = 0.0;
    long double r = 1e+9;
    long double eps = 1e-9;

    while(l+eps < r){
        long double mid = (l+r)/2;
        if(static_cast<unsigned long long> (L / mid) * static_cast<unsigned long long> (W / mid) * static_cast<unsigned long long> (H / mid) >= N){
            l = mid;
        }else{
            r = mid;
        }
    }
    
    std::cout << std::fixed;
    std::cout.precision(10);
    std::cout << r << '\n';

    return 0;
}