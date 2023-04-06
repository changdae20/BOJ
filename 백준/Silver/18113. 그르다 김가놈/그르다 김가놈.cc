#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout.tie(0);
    unsigned long long N, K, M, x;
    std::cin >> N >> K >> M;
    std::vector<unsigned long long> v;
    v.reserve(N);
    for (unsigned long long i = 0; i < N; ++i) {
        std::cin >> x;
        if(x <= K || x==2*K) continue;
        v.push_back((x>2*K) ? (x-2*K) : (x-K));
    }

    unsigned long long l = 0;
    unsigned long long r = 1000000000;

    while(l+1<r){
        unsigned long long mid = (l+r)/2;
        if(std::accumulate(v.begin(), v.end(), 0, [mid](unsigned long long a, unsigned long long b){return a + b/mid;}) >= M) l = mid;
        else r = mid;
    }
    if(l&&std::accumulate(v.begin(), v.end(), 0, [l](unsigned long long a, unsigned long long b){return a + b/l;}) >= M) std::cout << l << std::endl;
    else std::cout << -1 << std::endl;
    return 0;
}