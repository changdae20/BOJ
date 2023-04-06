#include <bits/stdc++.h>

int main( int argc, char *argv[] ) {
    std::cin.tie( 0 );
    std::ios::sync_with_stdio( false );
    std::cout.tie( 0 );
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif

    int N, M;
    std::cin >> N >> M;

    std::vector<int> DP(M+1, 0);

    int weight, value;
    while(N--){
        std::cin >> weight >> value;
        std::vector<int> old_DP(DP);
        for(int w=1; w<=M; ++w){
            if(w>=weight){
                DP[w] = std::max<>(old_DP[w], old_DP[w-weight]+value);
            }
        }

    }

    std::cout << DP[M] << std::endl;

    return 0;
}