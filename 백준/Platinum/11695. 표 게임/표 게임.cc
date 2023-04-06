#include <bits/stdc++.h>
typedef long long ll;
int main(){
    std::cin.tie(nullptr);std::cout.tie(nullptr);std::ios_base::sync_with_stdio(false);
    int N,M; std::cin >> N >> M;
    auto arr = std::vector<std::vector<ll>> ( N, std::vector<ll>( M, 0LL ));
    for(auto& row : arr)
    for(auto& el : row) std::cin >> el;
    std::cout << (std::accumulate(arr.begin(),arr.end(), 0LL,[](ll sum, auto &row){return sum ^ std::accumulate(row.begin(), row.end(), 0LL);}) ? "august14" : "ainta") << std::endl;
    return 0;
}