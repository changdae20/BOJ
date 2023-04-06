#include <bits/stdc++.h>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout.tie(0);
    
    unsigned long long N,M;
    std::cin >> N >> M;
    std::vector<unsigned long long> v(N);
    for(auto& el : v) std::cin >> el;

    unsigned long long l=0, r=2000000000;

    auto check = [&](unsigned long long N){
        return std::accumulate(v.begin(), v.end(), 0uLL, [N](unsigned long long acc, unsigned long long length){
            return acc + ((length > N) ? (length - N) : 0uLL);
        }) >= M;
    };

    while(l+1<r){
        auto mid = (l+r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }

    std::cout << l << std::endl;
    return 0;
}