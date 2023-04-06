#include <bits/stdc++.h>

unsigned long long cumulative_xor(unsigned long long N){
    switch(N&3uLL){
        case 0uLL:
            return N;
        case 1uLL:
            return 1uLL;
        case 2uLL:
            return N+1uLL;
        case 3uLL:
            return 0uLL;
    }
    return 0uLL;
}

unsigned long long grundy(unsigned long long X, unsigned long long M){
    return cumulative_xor(X-1uLL)^cumulative_xor(X+M-1uLL);
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int N;
    std::cin >> N;
    
    unsigned long long X,M;
    unsigned long long ans = 0;

    while(N--){
        std::cin >> X >> M;
        ans ^= grundy(X,M);
    }

    if(ans) std::cout << "koosaga" << std::endl;
    else std::cout << "cubelover" << std::endl;
    return 0;
}