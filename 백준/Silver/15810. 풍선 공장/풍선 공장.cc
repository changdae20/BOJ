#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout.tie(0);
    int N, M;
    std::cin >> N >> M;
    std::vector<unsigned long long> v(N);
    for(auto& el : v) std::cin >> el;

    unsigned long long l = 0, r = 1e12;
    while(l+1<r){
        auto mid = (l+r)/2;
        if(std::accumulate(v.begin(), v.end(), 0uLL, [mid](unsigned long long acc, int el){
            return acc + (mid/el);
        }) >= M) r = mid;
        else l = mid;
    }
    std::cout << r << std::endl;
    return 0;
}