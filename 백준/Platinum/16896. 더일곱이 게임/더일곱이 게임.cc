#include <bits/stdc++.h>

long long calc( long long N ) { // N-th winning number which koosaga will win
    if ( N == 1LL )
        return 1LL;
    if ( N == 2LL )
        return 3LL;

    if ( N & 1LL ) {
        return 4LL * calc( ( N + 1 ) / 2 ) - 3LL;
    } else {
        return 4LL * calc( N / 2 ) - 1LL;
    }
}

bool grundy( long long N ) { // find N can be output of calc function using binary search.
    long long l = 1;
    long long r = 1 << 30;

    while ( l < r ) {
        long long m = ( l + r ) / 2;
        if ( calc( m ) < N ) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    if ( calc( l ) == N )
        return true;
    return false;
}

int main() {
    std::cin.tie( nullptr );
    std::ios::sync_with_stdio( false );
    std::cout.tie( nullptr );
    int T;
    long long n;
    std::cin >> T;
    while ( T-- ) {
        std::cin >> n;
        std::cout << ( grundy( n ) ? "koosaga" : "cubelover" ) << '\n';
    }
    return 0;
}