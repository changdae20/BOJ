#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <chrono>
#include <assert.h>
#include <map>

int main(){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    #ifndef BOJ
    freopen("input.txt", "r", stdin);
    #endif

    int N, tmp1, tmp2;
    std::cin >> N >> tmp1 >> tmp2;

    std::vector<int> v(N+1);

    int zero_idx = 0;

    for(int i=0; i<tmp1; ++i){
        std::cin >> v[i];
        if(v[i] == 0) zero_idx = i;
    }

    for(int i=N; i>N-tmp2; --i){
        std::cin >> v[i];
        if(v[i] == 0) zero_idx = i;
    }

    int maxx = 0;
    int ans = 0;
    // 정방향
    for(int i = zero_idx; i>=0; --i){
        if(maxx<v[i]){
            maxx = v[i];
            ++ans;
        }
    }

    // 역방향
    maxx = 0;
    for(int i = zero_idx; i<=N; ++i){
        if(maxx<v[i]){
            maxx = v[i];
            ++ans;
        }
    }

    std::cout << ans << '\n';

    return 0;
}