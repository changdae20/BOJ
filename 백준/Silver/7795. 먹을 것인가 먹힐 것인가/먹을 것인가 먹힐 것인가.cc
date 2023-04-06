#include <bits/stdc++.h>

int main( int argc, char *argv[] ) {
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif
    std::cin.tie( NULL );
    std::ios::sync_with_stdio( false );
    std::cout.tie( NULL );

    int T;
    std::cin >> T;

    while ( T-- ) {
        int N, M;
        std::cin >> N >> M;
        std::vector<unsigned long long> A( N );
        std::vector<unsigned long long> B( M );

        for ( auto &el : A )
            std::cin >> el;
        for ( auto &el : B )
            std::cin >> el;

        std::sort( A.begin(), A.end() );
        std::sort( B.begin(), B.end() );

        auto it = B.begin();

        int ans = 0;
        for ( const auto &a : A ) {
            it = std::lower_bound( it, B.end(), a );
            ans += std::distance( B.begin(), it );
        }

        std::cout << ans << std::endl;
    }
    return 0;
}