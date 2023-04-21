#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
    std::string s;
    std::cin >> s;
    std::vector<char> _s;
    std::copy(s.begin(), s.end(), std::back_inserter(_s));
    std::sort(_s.begin(), _s.end(), std::greater<>());
    for(auto&el : _s) std::cout << el;
    std::cout << std::endl;

    return 0;
}