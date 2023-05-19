#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
	int N;
    std::cin >> N;

    std::vector<int> arr(N+1);
    for(int i=1; i<=N;++i) std::cin >> arr[i];
    
    auto dp = std::vector<std::vector<int>>(N+1, std::vector<int> (2, 0));

    dp[1][0] = arr[1];
    for(int i=2; i<=N; ++i){
        // 1칸 움직이는 경우
        dp[i][1] = std::max(dp[i][1], dp[i-1][0] + arr[i]);

        // 2칸 움직이는 경우
        if(i>=2){
            dp[i][0] = std::max(dp[i][0], dp[i-2][0] + arr[i]);
            dp[i][0] = std::max(dp[i][0], dp[i-2][1] + arr[i]);
        }
    }
    std::cout << std::max(dp[N][0], dp[N][1]) << std::endl;
    return 0;
}