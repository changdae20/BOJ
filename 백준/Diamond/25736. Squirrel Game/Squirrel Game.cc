#include <bits/stdc++.h>

int main(int argc, char* argv[]) {
    int M,N,K;
    std::cin >> M >> N >> K;

    unsigned int ans = 0u;
    std::vector<int> x(N+1,0);
    std::vector<std::vector<int>> distances(K, std::vector<int>());

    for(int i=1; i<=N; ++i){
        std::cin >> x[i];
        distances[i%K].push_back(x[i]-x[i-1]-1);
    }

    for(auto &row : distances){
        for(auto it = row.rbegin(); it!=row.rend(); it = std::next(it, std::min(2l, std::distance(row.begin(), it.base())))){
            ans ^= (*it);
        }
    }
    if(ans) std::cout << "Twinkle\n";
    else std::cout << "Nova\n";
    return 0;
}