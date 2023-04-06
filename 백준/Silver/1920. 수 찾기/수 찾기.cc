#include <bits/stdc++.h>

int main(int argc, char* argv[]){
#ifndef BOJ
    freopen(argv[1], "r", stdin);
#endif
    std::cin.tie(NULL);
    std::ios::sync_with_stdio( false );
    std::cout.tie(NULL);

    int N, M, x;
    std::set<int> s; // std::set은 원소 삽입과 제거, 탐색 모두 O(log N)임
    std::cin >> N;
    while(N--){
        std::cin >> x;
        s.insert(x);
    }

    std::cin >> M;
    while(M--){
        std::cin >> x;
        std::cout << static_cast<int>(s.count(x)) << '\n';
    }
    
    return 0;
}