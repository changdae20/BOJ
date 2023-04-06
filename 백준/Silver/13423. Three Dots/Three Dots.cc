#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout.tie(0);
    int T;
    std::cin >> T;
    while(T--){
        int N;
        std::cin >> N;
        std::vector<int> v(N);
        std::set<int> s;
        for(auto& el : v) std::cin >> el;
        for(auto& el : v) s.insert(el);
        std::sort(v.begin(), v.end());
        int ans = 0;
        for(int i=0; i<N-2; ++i){
            for(int j=i+2; j<N; ++j ){
                if((v[i]+v[j])%2) continue;
                ans += s.count((v[i]+v[j])/2);
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}