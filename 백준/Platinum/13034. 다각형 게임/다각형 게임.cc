#include <bits/stdc++.h>

std::vector<uint> dp(1001);

void bake(){
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    std::bitset<1000> bs;
    for(uint i=4; i<=1000; ++i){
        bs.reset();

        for(int j=0; j<=(i-j-2); j++){
            bs[dp[i-j-2] ^ dp[j]] = true;
        }

        for(int j=0; j<1000;++j){
            if(!bs[j]){
                dp[i] = j;
                break;
            }
        }
    }
    return;
}
int main() {
    std::cin.tie( nullptr );
    std::cout.tie( nullptr );
    std::ios_base::sync_with_stdio( false );
    int N;
    std::cin >> N;
    bake();

    std::cout << (dp[N] ? 1 : 2) << std::endl;

    return 0;
}