#include <bits/stdc++.h>

int main( int argc, char *argv[] ) {
    std::cin.tie( 0 );
    std::ios::sync_with_stdio( false );
    std::cout.tie( 0 );
#ifndef BOJ
freopen( argv[ 1 ], "r", stdin );
#endif
    int T;
    std::cin >> T;
    std::string s;
    for(int _case = 1; _case <=T; ++_case){
        std::cin >> s;
        std::array<int, 26> arr = {0, };
        for(char &c : s){
            ++arr[static_cast<int>(c - 'A')];
        }

        std::array<int, 10> ans = {0, };
        ans[0] = arr[25]; // Z
        ans[6] = arr[23]; // X
        ans[7] = arr[18] - ans[6];
        ans[5] = arr[21] - ans[7];
        ans[2] = arr[22];
        ans[8] = arr[6];
        ans[9] = arr[8] - ans[5] - ans[6] - ans[8];
        ans[4] = arr[5] - ans[5];
        ans[1] = arr[14] - ans[0] - ans[2] - ans[4];
        ans[3] = arr[19] - ans[2] - ans[8];

        std::cout << "Case #" << _case << ": ";
        for(size_t i = 0; i<10; ++i){
            for(int j = 0; j<ans[i]; ++j) std::cout << i;
        } 
        std::cout << "\n";
    }

    return 0;
}