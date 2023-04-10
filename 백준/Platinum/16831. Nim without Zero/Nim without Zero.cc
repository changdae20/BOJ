#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
	int N,x;
    int gn = 0;
    int count_odd = 0;
    std::cin >> N;
    while(N--){
        std::cin >> x;
        gn ^= x;
        if(gn&1) ++count_odd;
    }

    if(gn){
        std::cout << ((gn==1) ? "Bob" : "Alice") << std::endl;
    }else{
        std::cout << (count_odd ? "Alice" : "Bob") << std::endl;
    }

    return 0;
}