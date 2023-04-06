#include <bits/stdc++.h>

unsigned long long grundy(unsigned long long i, unsigned long long k){
    if(k&1){
        return i%2;
    }else{
        return (i%(k+1) == k) ? 2 : (i%(k+1))%2;
    }
}

int main(int argc, char** argv){
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif

    int T;

    std::cin >> T;
    while(T--){
        int N, K;
        std::cin >> N >> K;
        if(grundy(N,K)){
            for(int i=1;i<=N;){
                if(grundy(N-i,K)==0){
                    std::cout << i << '\n';
                    break;
                }
                i *= K;
            }
        }else{
            std::cout << 0 << '\n';
        }
    }

    return 0;
}