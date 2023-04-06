#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout.tie(0);
    int N;
    std::cin >> N;
    std::vector<int> v(N);
    for(auto& x : v) std::cin >> x;
    std::sort(v.begin(), v.end());
    unsigned long long ans = 0;
    for(int i=0; i<N; ++i){
        auto it = std::lower_bound(v.begin(), v.end(), ((v[i]*9)%10==0)? (v[i]*9)/10 : (v[i]*9)/10 + 1);
        ans += i - std::distance(v.begin(), it);
    }

    std::cout << ans << std::endl;

    return 0;
}