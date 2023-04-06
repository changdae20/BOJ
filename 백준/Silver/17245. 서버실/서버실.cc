#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout.tie(0);
    int N;
    unsigned long long total=0;
    std::cin >> N;
    std::vector<unsigned long long> v(N*N);
    for(auto& el : v){
        std::cin >> el;
        total += el;
    }

    unsigned long long l=0;
    unsigned long long r=10000000;

    while(l+1<r){
        unsigned long long mid = (l+r)/2uLL;
        if(std::accumulate(v.begin(), v.end(), 0uLL, [mid](unsigned long long a, unsigned long long b){return a + std::min<>(mid, b);}) >= ((total)/2uLL + (total&1uLL))) r = mid;
        else l = mid;
    }
    if(total==0uLL) std::cout << 0 << std::endl;
    else std::cout << r << std::endl;
    return 0;
}