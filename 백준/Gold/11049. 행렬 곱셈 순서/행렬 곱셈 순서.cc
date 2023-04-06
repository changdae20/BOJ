#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>

int get(int i, int j, std::vector<std::vector<int>>& dp, std::vector<std::pair<int,int>>& dimensions){
    if( dp[i][j] != -1 ){
        return dp[i][j];
    }else{
        if( i == j ){
            dp[i][j] = 0;
            return 0;
        } else{
            int min = -1;
            for( int k = i; k < j; ++k ){
                int cost = get(i, k, dp, dimensions) + get(k+1, j, dp, dimensions) + dimensions[i].first * dimensions[k].second * dimensions[j].second;
                if( min == -1 || min > cost ){
                    min = cost;
                }
            }
            dp[i][j] = min;
            return min;
        }
    }
}
int main(){
    #ifndef BOJ
    freopen("input.txt", "r", stdin);
    #endif

    int N;
    std::cin >> N;

    std::vector<std::pair<int,int>> dimensions(N);

    for(auto& [r,c] : dimensions){
        std::cin >> r >> c;
    }

    std::vector<std::vector<int>> dp(N, std::vector<int>(N, -1));

    std::cout << get(0, N-1, dp, dimensions) << std::endl;

}