#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio( false );std::cin.tie( NULL );std::cout.tie( NULL );

auto cmp = [](const std::string& a, const std::string& b) noexcept {
    if(a.size() != b.size()) return a.size() < b.size();
    else return strcmp(a.c_str(), b.c_str())<0;
};

int main( int argc, char *argv[] ) {
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif
    fastio;

    int N;
    std::cin >> N;
    std::set<std::string, decltype(cmp)> s(cmp);
    std::string line;
    while(N--){
        std::cin >> line;
        s.insert(line);
    }

    for(auto it = s.begin(); it != s.end(); ++it){
        std::cout << *it << '\n';
    }

    return 0;
}