#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio( false );std::cin.tie( NULL );std::cout.tie( NULL );

int main( int argc, char *argv[] ) {
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif
    fastio;

	int N, x;
	std::cin >> N;

    std::array<int, 2000001> divisor_counts = {0,};

    while(N--){
        std::cin >> x;
        for(int i=1; i*i <= x; ++i){
            if(x%i == 0){
                ++divisor_counts[i];
                ++divisor_counts[x/i];
            }
            if(i*i==x) --divisor_counts[i];
        }
    }

    long long ans = 0;
    for(long long i=1; i<=2000000; ++i){
        if(divisor_counts[i]>=2){
            ans = std::max(ans, i * divisor_counts[i]);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}