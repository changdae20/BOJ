#include <bits/stdc++.h>

int main(){
    #ifndef BOJ
    freopen("input.txt", "r",stdin);
    #endif

    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    while(N){
        if(N==1){
            std::cout << 0 << std::endl;
            std::cin >> N;
            continue;
        }
        int ans = N;
        for(int prime=2; prime*prime<=N; ++prime){
            if(N%prime==0){
                ans = ans - ans/prime;
                while(N%prime==0) N = N/prime;
            }
        }

        if(N>1) ans = ans - ans / N;

        std::cout << ans << std::endl;


        std::cin >> N;
    }

    return 0;
}