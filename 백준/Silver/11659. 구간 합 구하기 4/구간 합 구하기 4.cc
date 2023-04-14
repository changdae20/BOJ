#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
	int N,M,x;
    std::cin >> N >> M;
    std::vector<int> v(N+1);
    for(int i=1;i<=N;++i){
        std::cin >> x;
        v[i] = x + v[i-1];
    }
    
    int s,e;
    while(M--){
        std::cin >> s >> e;
        std::cout << (v[e] - v[s-1]) << '\n';
    }
    return 0;
}