#include <bits/stdc++.h>

int main() {
    std::cin.tie( nullptr );
    std::cout.tie( nullptr );
    std::ios_base::sync_with_stdio( false );
    
    int N, x;
    std::cin >> N;

    int ans = 0;
    int flag = 0;

    while(N--){
        std::cin >> x;
        if(x>1) ++flag;
        ans ^= x;
    }

    if( (!flag || ans) && (flag || ans!=1)) std::cout << "koosaga\n";
    else std::cout << "cubelover\n";
    return 0;
}