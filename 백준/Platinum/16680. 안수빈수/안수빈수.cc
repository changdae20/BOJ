#include <bits/stdc++.h>

int main(int argc, char* argv[]){
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif

    std::cin.tie( nullptr );std::cout.tie( nullptr );
    std::ios_base::sync_with_stdio( false );

    int T, N;
    std::cin >> T;
    while(T--){
        std::cin >> N;
        std::cout << N * 999999999LL << '\n';
    }
    return 0;
}