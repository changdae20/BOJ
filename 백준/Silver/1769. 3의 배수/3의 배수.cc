#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio( false );std::cin.tie( NULL );std::cout.tie( NULL );

int main( int argc, char *argv[] ) {
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif
    fastio;

    std::string s;
    std::cin >> s;

    int count = 0;
    while(s.length()>1){
        s = std::to_string(std::accumulate(s.begin(), s.end(), 0, [](int sum, auto& c){return sum + c - '0';}));
        ++count;
    }
    std::cout << count << std::endl;
    std::cout << (std::stoi(s)%3 ? "NO" : "YES") << std::endl;
    return 0;
}