#include <bits/stdc++.h>

std::vector<int> bake(int n){
    std::vector<int> v(n,0);

}
int grundy(int x){
    return x + (x%4==3 ? 1 : 0) + (x>0 && x%4==0 ? -1 : 0);
}

int main(int argc, char** argv){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif

    int N;
    std::cin >> N;
    int k;
    int ans = 0;
    while(N--){
        std::cin >> k;
        ans ^= grundy(k);
    }
    std::cout << (ans ? "koosaga" : "cubelover") << std::endl;
    
    return 0;
}