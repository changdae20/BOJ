#include <bits/stdc++.h>

int main(int argc, char* argv[]){
#ifndef BOJ
    freopen(argv[1], "r", stdin);
#endif
    std::cin.tie(NULL);
    std::ios::sync_with_stdio( false );
    std::cout.tie(NULL);
    
    long long N, K;

    std::cin >> N >> K;

    std::vector<long long> sticks(N, 0);
    for(auto& el : sticks) std::cin >> el;

    long long l = 0;
    long long r = INT_MAX+1LL;

    while(l+1 < r){
        long long mid = (l+r)/2;

        if(std::accumulate(sticks.begin(), sticks.end(), 0LL, [mid](long long acc, long long stick){
            return acc + (stick / mid);
        }) >= K){
            l = mid;
        }else r = mid;
    }

    std::cout << l << std::endl;

    return 0;
}