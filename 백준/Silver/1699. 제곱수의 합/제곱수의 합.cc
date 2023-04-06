#include <bits/stdc++.h>

int dp[100001];

int main(int argc, char** argv){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif

    int n;

    std::cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    int z=1;
    for(int i=3;i<=100000;i++) dp[i]=INT_MAX;
    for(int i=1;i*i<=100000;i++) dp[i*i]=1;

    for(int i = 3; i <= n; i++){
        for (int j=1; j*j<i; j++){
            dp[i] = std::min(dp[i], dp[j*j] + dp[i-j*j]);
        }
    }
    std::cout << dp[n] << std::endl;
    return 0;
}