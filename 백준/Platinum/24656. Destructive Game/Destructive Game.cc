#include <bits/stdc++.h>

int grundy(int N, int M){
    if(M&1) return N%2;

    if(N%(M+1) == M) return 2;
    else if((N%(M+1))%2) return 1;
    else return 0;
}

int main(int argc, char* argv[]){
    std::cin.tie(nullptr);std::cout.tie(nullptr);std::ios_base::sync_with_stdio(false);
    int N, a, b;
    int ans = 0;
    std::cin >> N;
    while(N--){
        std::cin >> a >> b;
        ans ^= grundy(a,b);
    }
    if(ans) std::cout << "Alice" << std::endl;
    else std::cout << "Bob" << std::endl;
    return 0;
}