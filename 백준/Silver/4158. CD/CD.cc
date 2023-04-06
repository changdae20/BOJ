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

    while(N!=0 || M!=0){
        std::vector<int> A(N);
        std::vector<int> B(M);

        for(auto& el : A) std::cin >> el;
        for(auto& el : B) std::cin >> el;

        std::cout << std::accumulate(A.begin(), A.end(), 0, [&B](int acc, int a){
            return acc + (a == *std::lower_bound(B.begin(), B.end(),a));
        }) << '\n';

        std::cin >> N >> M;
    }
    return 0;
}