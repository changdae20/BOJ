#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

bool solve(std::vector<int>& costs, int budget, int threshold){
    return budget >= std::accumulate(costs.begin(), costs.end(), 0, [threshold](int a, int b){
        return a + std::clamp(b, 0, threshold);
    });
}

int main(int argc, char* argv[]){
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif

    int N, M;
    std::cin >> N;
    std::vector<int> costs(N);
    for(auto& cost : costs){
        std::cin >> cost;
    }

    std::cin >> M;

    int l = 0, r = 1e5;

    while(l+1<r){
        int mid = (l+r)/2;
        if( solve(costs, M, mid) ){ // l = OK, mid = OK, r = NO
            l = mid;
        } else{
            r = mid;
        }
    }

    if(auto it = std::max_element(costs.begin(), costs.end()); *it <= l) std::cout << *it << std::endl;
    else std::cout << l << std::endl;

    return 0;
}