#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
    int N;
    std::cin >> N;
    std::vector<std::pair<int,int>> v(N);
    for(auto&el : v) std::cin >> el.second >> el.first;
    std::sort(v.begin(), v.end());
    for(auto&el : v) std::cout << el.second << ' ' << el.first << '\n';

    return 0;
}