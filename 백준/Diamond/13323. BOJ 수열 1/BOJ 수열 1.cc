#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

int main(int argc, char* argv[]) {
#ifndef BOJ
    freopen(argv[1], "r", stdin);
#endif
    fastio;

    int N;
    std::cin >> N;

    long long A;
    long long ans = 0;
    std::priority_queue<int, std::vector<int>, std::less<>> pq;

    for(int i=0; i<N; ++i){
        std::cin >> A;
        pq.push(A -= i);

        if(pq.top() > A && !pq.empty()){
            ans += (pq.top() - A);
            pq.pop();
            pq.push(A);
        }
    }
    std::cout << ans << std::endl;

    return 0;
}