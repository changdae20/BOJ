#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout.tie(0);
    int N,M;
    std::cin >> N >> M;
    std::vector<int> v(N);
    for(auto& x : v) std::cin >> x;
    std::sort(v.begin(), v.end());
    int x,y;
    while(M--){
        std::cin >> x >> y;
        std::cout << std::distance(std::lower_bound(v.begin(), v.end(),x), std::upper_bound(v.begin(), v.end(),y)) << '\n';
    }

    return 0;
}