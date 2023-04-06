#include <bits/stdc++.h>

std::vector<uint> dp(2001);

void bake(){
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    std::bitset<2000> bs;
    for(uint i=4; i<=2000; ++i){
        bs.reset();

        for(int j=1; 2*j<=(i+1); j++){
            int gn = dp[i-j-2] ^ (j>3 ? dp[j-3] : 0);
            bs[gn] = true;
        }

        for(int j=0; j<2000;++j){
            if(!bs[j]){
                dp[i] = j;
                break;
            }
        }
    }
    return;
}
int main() {
    #ifndef BOJ
    freopen("input.txt","r",stdin);
    #endif
    std::cin.tie( nullptr );
    std::cout.tie( nullptr );
    std::ios_base::sync_with_stdio( false );
    int N;
    std::cin >> N;
    bake();
    

    std::cout << (dp[N] ? 1 : 2) << std::endl;

    return 0;
}