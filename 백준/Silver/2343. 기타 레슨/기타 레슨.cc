#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int solve(std::vector<unsigned int>& costs, unsigned int capacity){ // capacity용량에 담으면 몇개만에 담아지는지
    unsigned int ans = 0u;
    unsigned int curr_capacity = capacity;
    for(auto& cost : costs){
        if(curr_capacity + cost > capacity){ // 새로 담아야 함
            if(cost > capacity) // 하나로도 담을 수 없는 경우 무조건 늘려야함 -> INT_MAX 리턴
                return INT32_MAX;
            ++ans;
            curr_capacity = cost;
        }else{
            curr_capacity += cost; // 기존거에 담음
        }
    }
    return ans;
}

int main(int argc, char* argv[]){
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif

    unsigned int N, M;
    std::cin >> N >> M;
    std::vector<unsigned int> costs(N);
    for(auto& cost : costs){
        std::cin >> cost;
    }

    unsigned int l = 0, r = 1e+9;

    while(l+1<r){
        unsigned int mid = (l+r)/2;
        if( solve(costs, mid) <= M ){ // l = NO, mid = OK, r = OK
            r = mid;
        } else{
            l = mid;
        }
    }
    std::cout << r << std::endl;

    return 0;
}