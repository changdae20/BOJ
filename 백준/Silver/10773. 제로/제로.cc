#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
    std::stack<long long> s;
    long long N,x;
    std::cin >> N;
    while(N--){
        std::cin >> x;
        if(x) s.push(x);
        else s.pop();
    }
    long long sum = 0;
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }
    std::cout << sum << std::endl;
    return 0;
}