#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout.tie(0);
    int N,M,K;
    std::cin >> N >> M >> K;
    std::vector<std::pair<int, int>> beers(K);
    for(auto& [a,b]: beers) {
        std::cin >> a >> b;
    }

    std::sort(beers.begin(), beers.end(), [](const auto& a, const auto& b) { // 도수별로 정렬
        return a.second < b.second;
    });

    unsigned long long l = 0uLL;
    unsigned long long r = 2147483647uLL;
    while(l+1<r){
        auto mid = (l+r)/2;
        auto it = std::upper_bound(beers.begin(), beers.end(), mid, [](const int& a, const std::pair<int,int>& b) { // 도수가 mid 이하인 것들의 개수
            return a < b.second;
        });
        int cnt = std::distance(beers.begin(), it);
        if( cnt < N) l = mid;
        else{
            std::sort(beers.begin(), it, [](const auto& a, const auto& b) { // 도수가 mid 이하인 것들을 다시 선호도 순으로 정렬
                return a.first < b.first;
            });
            int sum = std::accumulate(beers.begin()+cnt-N, beers.begin()+cnt, 0, [](const auto& a, const auto& b) { // 선호도 합
                return a+b.first;
            });
            if(sum < M) l = mid;
            else r = mid;
            std::sort(beers.begin(), it, [](const auto& a, const auto& b) { // 도수별로 다시 정렬
                return a.second < b.second;
            });
        }
    }
    auto it = std::upper_bound(beers.begin(), beers.end(), r, [](const auto& a, const auto& b) { // 도수가 r 이하인 것들의 개수
        return a < b.second;
    });
    int cnt = std::distance(beers.begin(), it);
    if( cnt < N) std::cout << -1;
    else{
        std::sort(beers.begin(), it, [](const auto& a, const auto& b) { // 도수가 r 이하인 것들을 다시 선호도 순으로 정렬
            return a.first < b.first;
        });
        int sum = std::accumulate(beers.begin()+cnt-N, beers.begin()+cnt, 0, [](const auto& a, const auto& b) { // 선호도 합
            return a+b.first;
        });
        if(sum < M) std::cout << -1;
        else std::cout << r;
    }
    std::cout << std::endl;
    return 0;
}