#include <bits/stdc++.h>

std::vector<uint> dp(5001);

void bake(){
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    std::bitset<5000> bs;
    for(uint i=4; i<=5000; ++i){
        bs.reset();

        for(int j=0; j<=(i-j-2); j++){
            bs[dp[i-j-2] ^ dp[j]] = true;
        }

        for(int j=0; j<5000;++j){
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
    int N,T;
	std::cin >> T;
    bake();

	while(T--){
		std::cin >> N;
    	std::cout << (dp[N] ? "First" : "Second") << std::endl;
	}

    return 0;
}